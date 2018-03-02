//
//  MultiTouchScene.h
//  MyCppGame
//
//  Created by cowell on 3/2/18.
//

#ifndef MultiTouchScene_h
#define MultiTouchScene_h

#include "cocos2d.h"

class MultiTouchScene: public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MultiTouchScene);
    
private:
    const static int MAX_TOUCHES = 5;
    
protected:
    cocos2d::Label* labelTouchLocation[MAX_TOUCHES];
};

#endif /* MultiTouchScene_hpp */
