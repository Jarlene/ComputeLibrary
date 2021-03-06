/*
 * Copyright (c) 2017 ARM Limited.
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
#ifndef __ARM_COMPUTE_GRAPH_L2NORMALIZE_LAYER_H__
#define __ARM_COMPUTE_GRAPH_L2NORMALIZE_LAYER_H__

#include "arm_compute/graph/GraphContext.h"
#include "arm_compute/graph/INode.h"
#include "arm_compute/graph/Tensor.h"
#include "arm_compute/graph/Types.h"

namespace arm_compute
{
namespace graph
{
/** L2Normalize layer node */
class L2NormalizeLayer final : public INode
{
public:
    /** Default Constructor
     *
     * @param[in] axis    Dimension along which to reduce.
     * @param[in] epsilon Lower bound value for the normalization.
     */
    explicit L2NormalizeLayer(unsigned int axis, float epsilon)
        : _axis(axis), _epsilon(epsilon)
    {
    }

    // Inherited methods overriden:
    std::unique_ptr<arm_compute::IFunction> instantiate_node(GraphContext &ctx, ITensor *input, ITensor *output) override;

private:
    unsigned int _axis;
    float        _epsilon;
};
} // namespace graph
} // namespace arm_compute
#endif /* __ARM_COMPUTE_GRAPH_L2NORMALIZE_LAYER_H__ */
