#include "PlayerHUD.h"

PlayerHUD::PlayerHUD()
{
    init();
}

PlayerHUD::~PlayerHUD()
{
}

bool PlayerHUD::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Current Score

    score_label = Label::createWithTTF(std::to_string(GameState::current().score), "fonts/Marker Felt.ttf", 24);
    score_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height - score_label->getContentSize().height));
    addChild(score_label, 1);

    auto score_icon = ui::ImageView::create("Assets/Score.png");
    score_icon->setPosition(Vec2(visibleSize.width / 2 + origin.x - 150, origin.y + visibleSize.height - score_label->getContentSize().height));
    score_icon->setScale(0.25);
    addChild(score_icon, 1);

    // Highest registered score

    high_score_label = Label::createWithTTF(std::to_string(Save::current().data->getFloatForKey("Score")), "fonts/Marker Felt.ttf", 24);
    high_score_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
        origin.y - 50 + visibleSize.height - high_score_label->getContentSize().height));
    addChild(high_score_label, 1);

    auto high_score_icon = ui::ImageView::create("Assets/Score.png");
    high_score_icon->setPosition(Vec2(visibleSize.width / 2 + origin.x - 150, origin.y - 50 + visibleSize.height - high_score_label->getContentSize().height));
    high_score_icon->setScale(0.25);
    addChild(high_score_icon, 1);

    scheduleUpdate();

    return true;
}

void PlayerHUD::update(float delta)
{
    score_label->setString(std::to_string(GameState::current().score));

    high_score_label->setString(std::to_string(Save::current().data->getFloatForKey("Score")));
}
