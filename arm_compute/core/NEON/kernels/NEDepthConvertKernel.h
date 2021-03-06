/*
 * Copyright (c) 2016, 2017 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef __ARM_COMPUTE_DEPTHCONVERTKERNEL_H__
#define __ARM_COMPUTE_DEPTHCONVERTKERNEL_H__

#include "arm_compute/core/NEON/INEKernel.h"
#include "arm_compute/core/Types.h"

#include <cstdint>

namespace arm_compute
{
class ITensor;

/** Depth conversion kernel */
class NEDepthConvertKernel : public INEKernel
{
public:
    /** Default constructor*/
    NEDepthConvertKernel();
    /** Prevent instances of this class from being copied (As this class contains pointers) */
    NEDepthConvertKernel(const NEDepthConvertKernel &) = delete;
    /** Default move constructor */
    NEDepthConvertKernel(NEDepthConvertKernel &&) = default;
    /** Prevent instances of this class from being copied (As this class contains pointers) */
    NEDepthConvertKernel &operator=(const NEDepthConvertKernel &) = delete;
    /** Default move assignment operator */
    NEDepthConvertKernel &operator=(NEDepthConvertKernel &&) = default;
    /** Set the input and output of the kernel
     *
     * Valid conversions Input -> Output :
     *
     *   - QS8 -> QS8, F32
     *   - U8 -> U16, S16, S32
     *   - U16 -> U8, U32
     *   - S16 -> U8, S32
     *   - QS16 -> QS16, F32
     *   - F32 -> QS8
     *
     * @warning In case of in-place fixed point position conversion make sure that configure has been called
     *          before the updated tensor is used in other functions, as the TensorInfo of the tensor will be
     *          altered. In-place is only supported for QS8 -> QS8, QS16 -> QS16.
     *
     * @param[in, out] input  The input tensor to convert (Written in case of in-place computation). Data types supported: U8/QS8/U16/S16/F32.
     * @param[out]     output The output tensor. Can be null in case of in-place computation. Data types supported: U8/QS8/U16/S16/U32/S32/F32.
     * @param[in]      policy Conversion policy.
     * @param[in]      shift  (Optional) Value for down/up conversions. Must be 0 <= shift < 8.
     *                         In case of fixed point position conversion, it specifies the new fixed point position, if operation is in-place.
     */
    void configure(ITensor *input, ITensor *output, ConvertPolicy policy, uint32_t shift = 0);

    // Inherited methods overridden:
    void run(const Window &window, const ThreadInfo &info) override;

private:
    ITensor      *_input;
    ITensor      *_output;
    ConvertPolicy _policy;
    uint32_t      _shift;
    int           _fixed_point_position_input;
    int           _fixed_point_position_output;
};
} // namespace arm_compute
#endif /*__ARM_COMPUTE_NEDEPTHCONVERTKERNEL_H__ */
