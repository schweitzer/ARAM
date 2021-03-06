/*
Copyright (c) 2014, Altran Research Medic@
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by Altran.
4. Neither the name of Altran nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY ALTRAN RESEARCH MEDIC@ ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ALTRAN RESEARCH MEDIC@ BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/





/**
*
* \file typedef.hpp
* \brief macro export definition
* \author Alexandre Kornmann
* \version 1.0
* \date 11 mars 2014
*
*/

#ifndef _TYPEDEF_HPP_
#define _TYPEDEF_HPP_

// OpenCV include
#include <opencv2/opencv.hpp>

// std include
#include <string>
#include <vector>

namespace aram
{	
	template <typename ROIDetector, typename TagType> class TagDetector;
	class ARAMException;

	class FrameSet;

	//ROIs
	class ROI;
	class IROIDetector;
	class AdaptiveThreshDetector;
	class CannyFittingDetector;
	
	//Tags
	class ITagMatcher;
	class HammingTagMatcher;
	class TagDictionnary;
	class HarrisCornerTagMatcher;
	class LocalThreshTagMatcher;

	//Coordinates
	class ICoordinate;
	class MultiTag;

	//Tools
	class TagDictionnary;
	class Extrinsic;
	class Intrinsic;
	class NaiveContourClosing;
	class MilgramContourClosing;


	/**
	* ARAM main detector
	*/
	typedef aram::TagDetector<aram::CannyFittingDetector,aram::LocalThreshTagMatcher> ARAMDetector;

	/**
	* Line (u0,v0,x0,y0)
	* u0,v0 -> unitary vector
	* x0,y0 -> origin point
	*/
	typedef cv::Vec4f Line;

	/**
	* Points in 3D space (world or object coordinates)
	*/
	typedef cv::Point3f Point3D;	
	
	/**
	* Point3D vector
	*/
	typedef std::vector<Point3D> vecPoint3D;

	/**
	* Iterator on Point3D vector
	*/
	typedef vecPoint3D::iterator iteratorPoint3D;
	
	/**
	* Const iterator on Point2D vector
	*/
	typedef vecPoint3D::const_iterator constIteratorPoint3D;

	/**
	* Points in 2D space (image coordinate)
	*/
	typedef cv::Point2f Point2D;

	/**
	* Point2D vector
	*/
	typedef std::vector<Point2D> vecPoint2D;
	
	/**
	* Iterator on Point2D vector
	*/
	typedef vecPoint2D::iterator iteratorPoint2D;

	/**
	* Const iterator on Point2D vector
	*/
	typedef vecPoint2D::const_iterator constIteratorPoint2D;

	/**
	* ROI* vector
	*/
	typedef std::vector<ROI*> vecTag;
	
	/**
	* Iterator on vecTag
	*/
	typedef vecTag::iterator iteratorTag;

	/**
	* ROI* vector
	*/
	typedef std::vector<ROI*> vecROI;
	
	/**
	* Iterator on ROI* vector 
	*/
	typedef vecROI::iterator iteratorROI;

	/**
	* Iterator on std::map<std::string,cv::Mat>
	*/
	typedef std::map<std::string,cv::Mat>::iterator iteratorFrameSet;

};

#endif