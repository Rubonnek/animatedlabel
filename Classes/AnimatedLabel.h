//
//  AnimatedLabel.h
//  AnimatedLabel
//
//  Created by Steven Barnegren on 23/03/2015.
//
//

/*
   Copyright (c) 2015 Steve Barnegren
   Copyright (c) 2017 Wilson E. Alvarez

   Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __AnimatedLabel_h__
#define __AnimatedLabel_h__

#include <stdio.h>
#include "cocos2d.h"

class AnimatedLabel : public cocos2d::Label
{
	public:

		// ONLY USE THIS FUNCTION FOR CREATION
		static AnimatedLabel* createWithBMFont(const std::string& bmfontFilePath, const std::string& text,const cocos2d::TextHAlignment& alignment = cocos2d::TextHAlignment::LEFT, int maxLineWidth = 0, const cocos2d::Vec2& imageOffset = cocos2d::Vec2::ZERO);
		static AnimatedLabel* createWithTTF(const std::string& text, const std::string& fontFile, float fontSize, const cocos2d::Size& dimensions = cocos2d::Size::ZERO, cocos2d::TextHAlignment hAlignment = cocos2d::TextHAlignment::LEFT, cocos2d::TextVAlignment vAlignment = cocos2d::TextVAlignment::TOP);

		//FUNCTIONS TO SET BASIC CHARACTER SPRITE PROPERTIES AT INDEX
		void setCharScale(int index, float s);
		void setCharOpacity(int index, float o);
		void setCharRotation(int index, float r);

		//FUNCTIONS TO SET BASIC PROPERTIES OF ALL CHARACTER SPRITES
		void setAllCharsScale(float s);
		void setAllCharsOpacity(float o);
		void setAllCharsRotation(float r);
		void offsetAllCharsPositionBy(cocos2d::Vec2 offset);

		//FUNCTIONS TO RUN CUSTOM ACTIONS ON CHARATER SPRITES
		void runActionOnSpriteAtIndex(int index, cocos2d::FiniteTimeAction* action);
		void runActionOnAllSprites(cocos2d::Action* action, bool removeOnCompletion = false, cocos2d::CallFunc *callFuncOnCompletion = nullptr);
		void stopActionsOnAllSprites();
		//For the 'run actions sequentially' functions, the duration refers to the
		//total time (in seconds) to complete actions on all letters, minus the duration of
		//the first action which is executed as soon as the label gets added as
		//a child to the scene.
		//Note: if there's a need to add a delay to the, using a Node::scheduleOnce will suffice.
		void runActionOnAllSpritesSequentially(cocos2d::FiniteTimeAction* action, float duration, float initialDelay = 0.f, bool removeOnCompletion = false, cocos2d::CallFunc *callFuncOnCompletion = nullptr);
		void runActionOnAllSpritesSequentiallyReverse(cocos2d::FiniteTimeAction* action, float duration, float initialDelay = 0.f, bool removeOnCompletion = false, cocos2d::CallFunc *callFuncOnCompletion = nullptr);

		//ANIMATIONS

		//fly ins
		void animateInFlyInFromLeft(float duration);
		void animateInFlyInFromRight(float duration);
		void animateInFlyInFromTop(float duration);
		void animateInFlyInFromBottom(float duration);

		//misc animate ins
		void animateInTypewriter(float duration, float initialDelay = 0.f, cocos2d::CallFunc *callFuncOnEach = nullptr, cocos2d::CallFunc *callFuncOnCompletion = nullptr);
		void animateInDropFromTop(float duration);
		void animateInSwell(float duration);
		void animateInRevealFromLeft(float duration);
		void animateInSpin(float duration, int spins);
		void animateInVortex(float duration, int spins, bool removeOnCompletion = false, bool createGhosts = true);

		//misc animations
		void animateSwell(float duration);
		void animateJump(float duration, float height);
		void animateStretchElastic(float stretchDuration, float releaseDuration, float stretchAmount);
		void animateRainbow(float duration);
		void flyPastAndRemove();
};

#endif /* __AnimatedLabel_h__ */
