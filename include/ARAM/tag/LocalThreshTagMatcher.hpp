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
* \file LocalThreshTagMatcher.hpp
* \brief Tag valdiation, using hamming correction, and local thresholding
* \author Alexandre Kornmann
* \version 1.3
* \date 24 juin 2014
*
*/

#ifndef _LOCALTHRESHTAGMATCHER_HPP_
#define _LOCALTHRESHTAGMATCHER_HPP_


//ARAM include
#include <ARAM/export.hpp>
#include <ARAM/typedef.hpp>
#include <ARAM/ARAMException.hpp>

#include <ARAM/tag/ITagMatcher.hpp>
#include <ARAM/tools/TagDictionnary.hpp>

namespace aram
{
	/** 
	* Tag with hamming correction. After sampling in ROI, it's use dictionnary of tag to find the nearest tag (the shortest hamming distance beetween sampling and dictionnary) to determine if this ROI is a tag or not.
	* Use otsu threshold after perspective.
	*/
	class ARAM_EXPORT LocalThreshTagMatcher : public ITagMatcher
	{
	public :
		/**
		* Constructor
		*
		* \param[in] FrameSet *fs FrameSet contains all current frame created by the library
		*/
		LocalThreshTagMatcher(FrameSet *fs);
		
		
		/**
		* check tag validity
		*
		* \param[in,out] ROI *roi Region of interest to check
		*/
		bool checkTag(ROI *roi);


	private :
		int m_tagSize; /**< tag size size in "bits number" (border include)*/
		int m_scale; /**< value of perspective scale */

		vecPoint2D m_dst; /**< Destination coordinates in 2D */
		TagDictionnary *m_bt; /**< Tag dictionnary */
	};
};

#endif