#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/ui/BasedButtonSprite.hpp>
#include "layers/galleryLayer.h"

using namespace cocos2d;
using namespace geode::prelude;

CCPoint AnchorPointZero = {
    0,
    0
};

class $modify(MyMenuLayer, MenuLayer) {
    void onMyButton(CCObject* sender) {
        auto scene = CCScene::create();
        auto layer = GalleryLayer::create();
        scene->addChild(layer);
        CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.05f, scene));
    }
    // Signature is `bool MenuLayer::init()`
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }
        

        // assuming you have a onMyButton function
        //set the button sprite
        auto spr = CircleButtonSprite::createWithSprite("logo.png"_spr);
        
        //create the menu button and set the position and anchor
        auto btn = CCMenuItemSpriteExtra::create(
            spr, this, menu_selector(MyMenuLayer::onMyButton)
        );
        btn->setPositionY(88);
        btn->setAnchorPoint(AnchorPointZero);

        // move the chest icon
        auto chestbtn = getChildByIDRecursive("daily-chest-button");
        chestbtn->setPositionX(24.250f);
        chestbtn->setPositionY(58);

        auto menu = this->getChildByID("right-side-menu"); // Define the right side of the menu
        menu->addChild(btn);
        

        return true;
    }
};