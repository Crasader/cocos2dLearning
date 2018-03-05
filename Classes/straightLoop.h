//
//  straightLoop.h
//  MyCppGame
//
//  Created by cowell on 3/2/18.
//

#include "cocos2d.h"

class straightLoop: public cocos2d::Layer {
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init() override;
    CREATE_FUNC(straightLoop);
    void update(float) override;
    
private:
    cocos2d::Sprite* car;
};

