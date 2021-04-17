#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bangtal.h>

SceneID scene1, scene2, scene3;
ObjectID start, rule, cookie[13], ready, finish, i, num, end, restart;
TimerID timer1;

ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown = true) {
    ObjectID object = createObject(image);
    locateObject(object, scene, x, y);
    if (shown) showObject(object);

    return object;
}

void timerCallback(TimerID timer) {
    if (timer == timer1) {
        showMessage("실패!!");
        stopTimer(timer1);
        for (i = 0; i <= 12; ++i) {
            showObject(cookie[i]);
        }
        showObject(restart);
        showObject(end);
    }
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
    if (object == rule) {

        enterScene(scene2);
    }
    else if (object == start) {

        enterScene(scene3);

    }
    else if (object == ready) {
        startTimer(timer1);
    }
    else if (object == finish) {
        showMessage("성공!!");
        stopTimer(timer1);
        for (i = 0; i <= 12; ++i) {
            showObject(cookie[i]);
        }
        showObject(restart);
        showObject(end);
    }
    else if (object == end) endGame();
    else if (object == restart) {
        stopTimer(timer1);
        setTimer(timer1, 5.0f);
        for (i = 0; i <= 12; ++i) {
            showObject(cookie[i]);
        }
    }
    for (num = 0; num <= 12; ++num) {
        if (object == cookie[num]) {
            hideObject(cookie[num]);
        }
    }

}

int main() {
    setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

    setMouseCallback(mouseCallback);
    setTimerCallback(timerCallback);

    scene1 = createScene("eat cookie", "ground1.png");
    rule = createObject("rules.png", scene1, 940, 50);

    scene2 = createScene("rule", "ground2.png");
    start = createObject("start.png", scene2, 940, 50);

    scene3 = createScene("go", "ground3.png");
    ready = createObject("ready.png", scene3, 1000, 600);
    finish = createObject("finish.png", scene3, 1000, 400);
    timer1 = createTimer(5.0f);
    showTimer(timer1);


    cookie[0] = createObject("cookie1.png", scene3, 940, 50);
    cookie[1] = createObject("cookie1.png", scene3, 50, 300);
    cookie[2] = createObject("cookie1.png", scene3, 640, 500);
    cookie[3] = createObject("cookie2.png", scene3, 480, 300);
    cookie[4] = createObject("cookie2.png", scene3, 350, 100);
    cookie[5] = createObject("cookie2.png", scene3, 30, 30);
    cookie[6] = createObject("cookie2.png", scene3, 200, 180);
    cookie[7] = createObject("cookie2.png", scene3, 700, 380);
    cookie[8] = createObject("cookie2.png", scene3, 600, 50);
    cookie[9] = createObject("cookie2.png", scene3, 60, 550);
    cookie[10] = createObject("cookie2.png", scene3, 280, 600);
    cookie[11] = createObject("cookie2.png", scene3, 450, 500);
    cookie[12] = createObject("cookie2.png", scene3, 750, 200);

    restart = createObject("restart.png", scene3, 1000, 300, false);
    end = createObject("end.png", scene3, 1150, 300, false);

    startGame(scene1);
}