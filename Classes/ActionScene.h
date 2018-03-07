//
//  ActionScene.h
//  MyCppGame
//
//  Created by cowell on 3/5/18.
//

#include "cocos2d.h"

class ActionScene: public cocos2d::Scene {
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    CREATE_FUNC(ActionScene);
private:
    cocos2d::Sprite* car;
};
