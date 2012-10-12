/*
 * Software License Agreement (BSD License)
 *
 *  Point Cloud Library (PCL) - www.pointclouds.org
 *  Copyright (c) 2011, Willow Garage, Inc.
 *
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id: pairwise_graph_registration.h 6459 2012-07-18 07:50:37Z dpb $
 *
 */

#ifndef PCL_PAIRWISE_GRAPH_REGISTRATION_H_
#define PCL_PAIRWISE_GRAPH_REGISTRATION_H_

#include <pcl/registration/graph_registration.h>
#include <pcl/registration/registration.h>

namespace pcl
{
  /** \brief @b PairwiseGraphRegistration class aligns the clouds two by two
    * \author Nicola Fioraio
    * \ingroup registration
    */
  template <typename GraphT, typename PointT>
  class PairwiseGraphRegistration : public GraphRegistration<GraphT>
  {
    public:
      using GraphRegistration<GraphT>::graph_handler_;
      using GraphRegistration<GraphT>::last_aligned_vertex_;
      using GraphRegistration<GraphT>::last_vertices_;

      typedef typename Registration<PointT, PointT>::Ptr RegistrationPtr;
      typedef typename pcl::registration::GraphHandler<GraphT>::Vertex GraphHandlerVertex;

      /** \brief Empty constructor */
      PairwiseGraphRegistration () : registration_method_ (), incremental_ (true)
      {}
      /** \brief Constructor */
      PairwiseGraphRegistration (const RegistrationPtr& reg, bool incremental) : registration_method_ (reg), incremental_ (incremental)
      {}

      /** \brief Set the registration object */
      inline void
      setRegistrationMethod (const RegistrationPtr& reg)
      {
        registration_method_ = reg;
      }

      /** \brief Get the registration object */
      inline RegistrationPtr
      getRegistrationMethod ()
      {
        return registration_method_;
      }

      /** \brief If True the initial transformation is always set to the Identity */
      inline void
      setIncremental (bool incremental)
      {
        incremental_ = incremental;
      }

      /** \brief Is incremental ? */
      inline bool
      isIncremental () const
      {
        return incremental_;
      }

    protected:
      /** \brief The registration object */
      RegistrationPtr registration_method_;
      /** \brief If True the initial transformation is always set to the Identity */
      bool incremental_;

    private:
      /** \brief The registration method */
      virtual void
      computeRegistration ();
  };
}

#include <pcl/registration/impl/pairwise_graph_registration.hpp>

#endif // PCL_PAIRWISE_GRAPH_REGISTRATION_H_