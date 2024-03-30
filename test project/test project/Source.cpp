#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<fstream>
using namespace std;
using namespace sf;
int setting_choice;
bool VOlume = 1;
float groundV;
float pipeV;
float gx = 0;
float gravity;
float jump;
double bird_velocity;
int v = bird_velocity;
float V_Before_Stop = pipeV;


// Text Functions
void _score_text(Text& ourscore, Font& font)
{
    ourscore.setFillColor(Color::White);
    ourscore.setFont(font);
    font.loadFromFile("font.ttf");
    ourscore.setCharacterSize(40);
    ourscore.setString("0");
    ourscore.setPosition(300, 50);
}
void _Bestscore_text(Text& best, Font& Best_score)
{
    best.setFillColor(Color::White);
    best.setFont(Best_score);
    Best_score.loadFromFile("font.ttf");
    best.setCharacterSize(20);
    best.setPosition(390, 290);
}
void _Start_text(Text& starttext, Font& startText)
{
    starttext.setFillColor(Color::Red);
    starttext.setFont(startText);
    startText.loadFromFile("font.ttf");
    starttext.setCharacterSize(30);
    starttext.setString("Press Enter To Start");
    starttext.setPosition(160, 550);
}
void _Level_text(Text& leveltext, Font& levelText)
{
    leveltext.setFillColor(Color::White);
    leveltext.setFont(levelText);
    levelText.loadFromFile("font.ttf");
    leveltext.setCharacterSize(30);
    leveltext.setString("Level");
    leveltext.setPosition(490, -5);
}
void _chooseBird_text(Text& choosetext, Font& chooseText)
{
    choosetext.setFillColor(Color::Blue);
    choosetext.setFont(chooseText);
    chooseText.loadFromFile("font.ttf");
    choosetext.setCharacterSize(35);
    choosetext.setString("Choose Your Bird");
    choosetext.setPosition(150, 40);
}
void _easy_text(Text& Easytext, Font& easyText)
{
    Easytext.setFillColor(Color::Yellow);
    Easytext.setFont(easyText);
    easyText.loadFromFile("font.ttf");
    Easytext.setCharacterSize(25);
    Easytext.setString("Easy");
    Easytext.setPosition(160, 260);
}
void _hard_text(Text& Hardtext, Font& hardText)
{
    Hardtext.setFillColor(Color::Red);
    Hardtext.setFont(hardText);
    hardText.loadFromFile("font.ttf");
    Hardtext.setCharacterSize(25);
    Hardtext.setString("Hard");
    Hardtext.setPosition(410, 260);
}
void _Top3_text(Text& top_3, Font& Top_3)
{
    top_3.setFont(Top_3);
    Top_3.loadFromFile("font.ttf");
    top_3.setCharacterSize(35);
    top_3.setFillColor(Color::Black);

}
// Sound Functions
void Point_sound(SoundBuffer& pointSound, Sound& Point)
{
    Point.setBuffer(pointSound);
    pointSound.loadFromFile("point.wav");
    Point.setVolume(100.0f);
    Point.play();
}
void Wing_sound(SoundBuffer& wingSound, Sound& Wing)
{
    wingSound.loadFromFile("wing.wav");
    Wing.setBuffer(wingSound);
    Wing.setVolume(100.0f);
    Wing.play();
}

void Hit_sound(SoundBuffer& hitSound, Sound& Hit)
{
    hitSound.loadFromFile("hit.wav");
    Hit.setBuffer(hitSound);
    Hit.setVolume(100.0f);
    Hit.play();

}
void Die_sound(SoundBuffer& dieSound, Sound& die)
{
    dieSound.loadFromFile("die.wav");
    die.setBuffer(dieSound);
    die.setVolume(100.0f);
    die.play();
}
void Level_sound(SoundBuffer& levelSound, Sound& levell)
{
    levelSound.loadFromFile("level.wav");

    levell.setBuffer(levelSound);
    levell.setVolume(100.0f);
    levell.play();
}
void Button_sound(SoundBuffer& buttonSound, Sound& button)
{
    buttonSound.loadFromFile("button.wav");
    button.setBuffer(buttonSound);
    button.setVolume(100.0f);
    button.play();
}
void Medal_sound(SoundBuffer& MedalSound, Sound& medal)
{
    MedalSound.loadFromFile("medal.wav");

    medal.setBuffer(MedalSound);
    medal.setVolume(100.0f);

}
// best score functions
int LoadBestScore() {
    int best_score = 0;
    ifstream file("Best.txt");
    if (file.is_open()) {
        file >> best_score;
        file.close();
    }
    return best_score;
}

void saveBestScore(int best_score) {
    ofstream file("Best.txt");
    if (file.is_open()) {
        file << best_score;
        file.close();
    }
}
int best_score = LoadBestScore();
int Top3[3] = { 0,0,0 };
// top 3 functions
int LoadTop3() {
    int best_score = 0;
    ifstream file("Top 3.txt");
    if (file.is_open()) {
        file >> Top3[0] >> Top3[1] >> Top3[2];

        file.close();
    }
    for (int i = 0; i < 3; i++) {
        return Top3[i];
    }
}
void saveTop3(int Top3[3]) {
    ofstream file("Top 3.txt");
    if (file.is_open()) {
        file << Top3[0] << "\n" << Top3[1] << "\n" << Top3[2];
        file.close();
    }
}
void sprite_Top3(Texture& Top3, Sprite& top3)
{

    Top3.loadFromFile("Top3.jpg");
    top3.setTexture(Top3);
    top3.setPosition(400, 400);
}
void Top3menu(int& next, RenderWindow& window, SoundBuffer& buttonSound, Sound& button) {
    if (next == 3 && Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousp = Mouse::getPosition(window);

        if (next == 3 && mousp.x > 400 && mousp.x < 490 && mousp.y>400 && mousp.y < 490) {
            next = 4;
            if (VOlume == 1)
                Button_sound(buttonSound, button);
        }
    }
    if (next == 4 && Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousp = Mouse::getPosition(window);

        if (next == 4 && mousp.x > 10 && mousp.x < 90 && mousp.y>20 && mousp.y < 90) {
            next = 3;
            if (VOlume == 1)
                Button_sound(buttonSound, button);
        }
    }

}
void top3arrange(int& next, int& score) {
    //top 3 sorting
    if (next == 3 && score > Top3[0]) {
        Top3[2] = Top3[1];
        Top3[1] = Top3[0];
        Top3[0] = score;

    }
    if (next == 3 && score > Top3[1] && score < Top3[0]) {
        Top3[2] = Top3[1];
        Top3[1] = score;
    }
    else if (next == 3 && score > Top3[2] && score < Top3[1]) {

        Top3[2] = score;
    }



}
// bird functions
void yellow(Texture& Flappy, Sprite& bird) {

    bird.setTexture(Flappy);
    bird.setTextureRect(IntRect(0, 0, 150, 115));
    bird.setPosition(150, 300);
    bird.setScale(0.3, 0.3);
    bird_velocity = 0;
    v = bird_velocity;
    Flappy.loadFromFile("flappy 3.png");
    bird.setRotation(0);
}
void Red(Texture& Flappy, Sprite& bird) {

    bird.setTexture(Flappy);
    bird.setTextureRect(IntRect(0, 0, 150, 115));
    bird.setPosition(150, 300); bird.setScale(0.3, 0.3);
    bird_velocity = 0;
    v = bird_velocity;
    Flappy.loadFromFile("red.png");
    bird.setRotation(0);
}
void Bird_Move(Texture& Flappy, Sprite& bird, int& i) {
    bird_velocity = -jump;
    i++;
    i %= 3;
    bird.setTextureRect(IntRect(i * 150, 0 * 115, 150, 115));

}
void Bird_Limit(Sprite& bird, int& next) {
    if ((bird.getPosition().y + bird.getGlobalBounds().height > 587)) {
        bird.setPosition(bird.getPosition().x, 587 - bird.getGlobalBounds().height);
        bird_velocity = 0.0f;
    }
    if (bird.getPosition().y < 0) {
        bird.setPosition(bird.getPosition().x, 0);
        bird_velocity = 0.0f;
    }
    if (next == 2) {
        bird_velocity += gravity;
    }
}
// pipes
struct PIPES {
    Texture topPipeTexture;
    Texture bottomPipeTexture;

    Sprite topPipe;
    Sprite bottomPipe;

    int PipeHeight;
    int PipeHeight2;


}p, p2;
void sprite_pipes(int PipeHeight, int PipeHeight2, Texture& topPipeTexture, Texture& bottomPipeTexture,
    Sprite& topPipe, Sprite& bottomPipe)
{
    p.topPipeTexture.loadFromFile("topp.png");
    p.bottomPipeTexture.loadFromFile("bottomm.png");
    p2.topPipeTexture.loadFromFile("topp.png");
    p2.bottomPipeTexture.loadFromFile("bottomm.png");
    p.topPipe.setTexture(p.topPipeTexture);
    p2.topPipe.setTexture(p2.topPipeTexture);
    p.bottomPipe.setTexture(p.bottomPipeTexture);
    p2.bottomPipe.setTexture(p2.bottomPipeTexture);
    p.topPipe.setPosition(800, p.PipeHeight);
    p2.topPipe.setPosition(p.topPipe.getPosition().x + 400, p2.PipeHeight2);
    p.bottomPipe.setPosition(800, p.topPipe.getPosition().y + 620);
    p2.bottomPipe.setPosition(p.topPipe.getPosition().x + 400, p2.topPipe.getPosition().y + 620);


}
void sprite_pipesLimit(int PipeHeight, int PipeHeight2, int& next, bool& increased, bool& increaseLevel, Texture& topPipeTexture, Texture& bottomPipeTexture,
    Sprite& topPipe, Sprite& bottomPipe
)
{
    p.PipeHeight = (-400 + rand() % 350);
    p2.PipeHeight2 = (-400 + rand() % 350);
    if (next == 2 && p.topPipe.getPosition().x + 100 < 0)
    {
        topPipe.setPosition(p2.topPipe.getPosition().x + 400, p.PipeHeight);
        bottomPipe.setPosition(p2.bottomPipe.getPosition().x + 400, p.topPipe.getPosition().y + 620);
        increased = 0;
        increaseLevel = 0;

    }

    if (next == 2 && p2.topPipe.getPosition().x + 100 < 0)
    {

        p2.topPipe.setPosition((p.topPipe.getPosition().x + 400), p2.PipeHeight2);

        p2.bottomPipe.setPosition((p.bottomPipe.getPosition().x + 400), p2.topPipe.getPosition().y + 620);
        increased = 0;
        increaseLevel = 0;
    }
}
void movepipes(Texture& topPipeTexture, Texture& bottomPipeTexture, Sprite& topPipe, Sprite& bottomPipe)
{
    p.topPipe.move(pipeV, 0);
    p.bottomPipe.move(pipeV, 0);
    p2.topPipe.move(pipeV, 0);
    p2.bottomPipe.move(pipeV, 0);
}
// choose bird
void sprite_choose_bird(int i, int y, Texture& yellow_Start_Flappy, Sprite& Yellow_Start_Flappy, string image, int posX, int posY)
{
    yellow_Start_Flappy.loadFromFile(image);
    Yellow_Start_Flappy.setTexture(yellow_Start_Flappy);
    Yellow_Start_Flappy.setTextureRect(IntRect(i, y, 150, 115));
    Yellow_Start_Flappy.setPosition(posX, posY);
    Yellow_Start_Flappy.setScale(0.5, 0.5);

}
void choose(int& next, bool& chosenBird, Texture& Flappy, Sprite& bird, RenderWindow& window, float& pipeV, float& groundV,
    SoundBuffer& buttonSound, Sound& button) {

    if (next == 0 && Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousp = Mouse::getPosition(window);

        if (next == 0 && mousp.x > 150 && mousp.x < 300 && mousp.y>300 && mousp.y < 415) {
            next = 1;
            chosenBird = 0;
            pipeV = -0.5;
            groundV = 0.55;
            bird_velocity = -jump;
            jump = 0.6;
            gravity = 0.007;
            yellow(Flappy, bird);
            if (VOlume == 1)
                Button_sound(buttonSound, button);
        }
    }
    if (next == 0 && Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousp = Mouse::getPosition(window);

        if (next == 0 && mousp.x > 400 && mousp.x < 550 && mousp.y>300 && mousp.y < 415) {
            next = 1;
            chosenBird = 1;
            Red(Flappy, bird);
            pipeV = -0.8;
            groundV = 0.7;
            bird_velocity = -jump;
            jump = 0.6;
            gravity = 0.007;
            if (VOlume == 1)
                Button_sound(buttonSound, button);
        }
    }
}
// back ground
struct backk {
    Texture BackGround;
    Sprite back;
}Back;
void sprite_back(Texture& BackGround, Sprite& back)
{
    BackGround.loadFromFile("flappyback.png");
    back.setTexture(BackGround);
    back.setTextureRect(IntRect(0, 0, 600, 925));
}
// ground
void sprite_ground(Texture& G, Sprite& ground)
{
    G.loadFromFile("ground.png");
    ground.setTexture(G);
    ground.setPosition(0, 585);

}
void ground_Move(Sprite& ground) {
    gx -= groundV;

    if (gx < -600) {
        gx += 600;
    }
    ground.setPosition(gx, ground.getPosition().y);
}
//Tap,get ready
void sprite_Tapp(Texture& Tap, Sprite& tap, Texture& Get, Sprite& ready)
{

    Tap.loadFromFile("tap.png");
    tap.setTexture(Tap);
    tap.setPosition(150, 200);



    Get.loadFromFile("get ready.png");
    ready.setTexture(Get);
    ready.setTexture(Get);
    ready.setPosition(150, 100);


}
// menu,play again
void sprite_Menu(Texture& Menu, Sprite& menu, Texture& Again, Sprite& again)
{

    Menu.loadFromFile("score.png");
    menu.setTexture(Menu);
    menu.setPosition(150, 190);

    Again.loadFromFile("again.jpg");
    again.setTexture(Again);
    again.setPosition(220, 380);
}
//medal
void sprite_Medal(Texture& Medal_silver, Texture& Medal_gold, Sprite& medal_silver, Sprite& medal_gold)
{
    Medal_silver.loadFromFile("silver.png");
    Medal_gold.loadFromFile("gold.png");
    medal_silver.setTexture(Medal_silver);
    medal_gold.setTexture(Medal_gold);
    medal_silver.setScale(0.14, 0.14);
    medal_gold.setScale(0.19, 0.19);
}

//back to
void sprite_Back_TO(Texture& Back_To, Sprite& back_to)
{

    Back_To.loadFromFile("back to.jpg");
    back_to.setTexture(Back_To);
    back_to.setPosition(10, 20);
    back_to.setScale(0.41, 0.41);
}

// stop struct
struct Stopp {
    Texture stopAndContinue;

    Sprite Stop;

}stopp;

void stopp_Function()
{
    bird_velocity = 0;
    gravity = 0;
    jump = 0;
    groundV = 0;
    V_Before_Stop = pipeV;
    pipeV = 0;

}
void continuee()
{
    bird_velocity = -jump;
    pipeV = V_Before_Stop;
    groundV = 0.5;
    jump = 0.6;
    gravity = 0.007;

}
// play again
void Play_Again(int& next, bool& restart, RenderWindow& window) {
    if (next == 3 && Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousp = Mouse::getPosition(window);

        if (next == 3 && mousp.x > 220 && mousp.x < 380 && mousp.y>380 && mousp.y < 468) {
            window.close();
            restart = 1;

        }
    }
}
// collision
void Collision(int& next, Sprite& bird) {
    bird.setPosition(bird.getPosition().x, bird.getPosition().y);
    groundV = 0;
    pipeV = 0;
    bird.setRotation(90);
    next = 3;

}
// level
void levels(bool& increaseLevel, Sprite& bird, int& next, Text& leveltext, int& level, SoundBuffer levelSound, Sound& levell, int& score) {
    if (bird.getPosition().x > p.topPipe.getPosition().x || bird.getPosition().x > p2.topPipe.getPosition().x) {
        increaseLevel = 1;
    }
    leveltext.setString("Level  " + to_string(level));

    if (next == 2 && !increaseLevel && score != 0 && score % 4 == 0) {
        level++;
        pipeV += -0.1;
        V_Before_Stop += -0.1;
        increaseLevel = 1;
        if (VOlume == 1)
            Level_sound(levelSound, levell);
    }

}


//Settings
void sprite_Settings(Texture& Settings, Texture& All, Texture& Reset, Texture& Soundd, Texture& Mute
    , Sprite& settings, Sprite& all, Sprite& reset, Sprite& sound, Sprite& mute)
{
    Settings.loadFromFile("set1.png");
    All.loadFromFile("allset.png");
    Reset.loadFromFile("reset.png");
    Soundd.loadFromFile("sound on.png");
    Mute.loadFromFile("mute.png");

    settings.setTexture(Settings);
    settings.setPosition(10, 20);
    settings.setScale(0.6, 0.6);
    all.setTexture(All);
    all.setPosition(8, 12);
    all.setScale(0.63, 0.63);

    sound.setTexture(Soundd);
    sound.setPosition(5, 0.001);
    sound.setScale(0.73, 0.73);

    mute.setTexture(Mute);
    mute.setPosition(70, 13);
    mute.setScale(0.73, 0.73);
    reset.setTexture(Reset);
    reset.setScale(0.73, 0.73);
    reset.setPosition(6, 90);
}
void Setting_Choice(int& next, int& setting, int best_score, RenderWindow& window, SoundBuffer& buttonSound, Sound& button) {
    if (next == 1 && Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousp = Mouse::getPosition(window);

        if (setting == 0 && next == 1 && mousp.x > 8 && mousp.x < 67 && mousp.y>12 && mousp.y < 62) {

            setting = 1;
            if (VOlume == 1)
                Button_sound(buttonSound, button);
        }
    }

    if (setting == 1 && next == 1 && Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousp = Mouse::getPosition(window);
        int best_score = LoadBestScore();


        if (setting == 1 && next == 1 && mousp.x > 8 && mousp.x < 67 && mousp.y>12 && mousp.y < 62) {


            setting_choice = 1;
            VOlume = 1;


        }
    }
    if (next == 1 && Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousp = Mouse::getPosition(window);
        int best_score = LoadBestScore();


        if (setting == 1 && next == 1 && mousp.x > 80 && mousp.x < 139 && mousp.y>8 && mousp.y < 80) {

            setting_choice = 2;
            VOlume = 0;


        }
    }
    if (next == 1 && Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousp = Mouse::getPosition(window);

        if (setting == 1 && next == 1 && mousp.x > 8 && mousp.x < 67 && mousp.y>100 && mousp.y < 150) {

            setting_choice = 3;
            best_score = 0;
            for (int i = 0; i < 3; i++) {
                Top3[i] = 0;


            }
            saveTop3(Top3);
            saveBestScore(best_score);


        }
    }
    if (next == 1 && Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousp = Mouse::getPosition(window);

        if (setting == 1 && next == 1 && mousp.x > 80 && mousp.x < 209 && mousp.y>113 && mousp.y < 150) {


            setting = 0;
            if (VOlume == 1)
                Button_sound(buttonSound, button);

        }
    }


}
//***************************************************************



//Game Function
void game() {

    // Variables
    int i = 0, y = 0;
    bool increased = 0;
    bool increaseLevel = 0;
    bool restart = 0;
    bool chosenBird = 0;
    bool  SilverMedalAppear = 1;
    bool stop = 0;
    int Medal = 0;
    int  MedalAppear = 0;
    float delta = 0;
    double dely = 0.5;
    int next = 0;
    int score = 0;
    int level = 1;
    int best_score = LoadBestScore();
    int setting = 0;
    //****************************************************
    RenderWindow window(VideoMode(600, 635), "flappy bird");
    window.setFramerateLimit(400);

    //Call Functions Of Page 1

         //yellow start bird
    Texture yellow_Start_Flappy;
    Sprite Yellow_Start_Flappy;
    sprite_choose_bird(i, y, yellow_Start_Flappy, Yellow_Start_Flappy, "flappy 3.png", 150, 300);

    //red start bird
    Texture red_Start_Flappy;
    Sprite Red_Start_Flappy;
    sprite_choose_bird(i, y, red_Start_Flappy, Red_Start_Flappy, "red.png", 400, 300);

    //back

    sprite_back(Back.BackGround, Back.back);
    //ground

    Texture G;
    Sprite ground;
    sprite_ground(G, ground);
    //Flappy bird
    Texture Flappy;
    Sprite bird;
    Clock gameclock;
    //pipes

    p.PipeHeight = (-400 + rand() % 350);
    p2.PipeHeight2 = (-400 + rand() % 350);
    sprite_pipes(p.PipeHeight, p.PipeHeight2, p.topPipeTexture, p.bottomPipeTexture, p.topPipe, p.bottomPipe
    );

    //stop and continue

    stopp.stopAndContinue.loadFromFile("stopp.png");
    stopp.Stop.setTexture(stopp.stopAndContinue);
    stopp.Stop.setTextureRect(IntRect(i, y, 47, 47));
    stopp.Stop.setPosition(20, 5);
    //score text
    Font font;
    Text ourscore;
    _score_text(ourscore, font);
    // Best score
    Font Best_score;
    Text best;
    _Bestscore_text(best, Best_score);
    //start text 
    Font startText;
    Text starttext;
    _Start_text(starttext, startText);
    //level text 
    Font levelText;
    Text leveltext;
    _Level_text(leveltext, levelText);
    // choose bird text
    Font chooseText;
    Text choosetext;
    _chooseBird_text(choosetext, chooseText);
    // "easy" text
    Font easyText;
    Text Easytext;
    _easy_text(Easytext, easyText);

    // "hard" text
    Font hardText;
    Text Hardtext;
    _hard_text(Hardtext, hardText);

    // top 3 text
    Font Top_3[3];
    Text top_3[3];
    _Top3_text(top_3[0], Top_3[0]);
    top_3[0].setPosition(10, 100);

    _Top3_text(top_3[1], Top_3[1]);
    top_3[1].setPosition(10, 200);

    _Top3_text(top_3[2], Top_3[2]);
    top_3[2].setPosition(10, 300);

    //game over menu
    Texture GO;
    GO.loadFromFile("gameover.png");
    Sprite go;
    go.setTexture(GO);
    go.setPosition(150, 100);

    // score and medal menu
    Texture  Menu;
    Sprite menu;
    //play again
    Texture Again;
    Sprite again;
    sprite_Menu(Menu, menu, Again, again);
    //Call Functions Of Page 2

    //get ready
    Texture Get;
    Sprite ready;


    //tap
    Texture Tap;
    Sprite tap;
    sprite_Tapp(Tap, tap, Get, ready);
    //medal 
    Texture Medal_silver, Medal_gold;
    Sprite medal_silver, medal_gold;
    sprite_Medal(Medal_silver, Medal_gold, medal_silver, medal_gold);
    //settings
    Texture Settings, All, Reset, Soundd, Mute;
    Sprite settings, all, reset, sound, mute;
    sprite_Settings(Settings, All, Reset, Soundd, Mute
        , settings, all, reset, sound, mute);
    // top 3
    Texture Topp3;
    Sprite topp3;
    sprite_Top3(Topp3, topp3);
    LoadTop3();
    // back to
    Texture Back_To;
    Sprite back_to;
    sprite_Back_TO(Back_To, back_to);
    //Sounds 
      // point sound

    SoundBuffer pointSound;
    Sound Point;



    //wing sound

    SoundBuffer wingSound;
    Sound Wing;

    // hit sound

    SoundBuffer hitSound;
    Sound Hit;

    // die sound

    SoundBuffer dieSound;
    Sound die;

    //level sound 

    SoundBuffer levelSound;
    Sound levell;


    //button sound 

    SoundBuffer buttonSound;
    Sound button;


    //Medal sound 

    SoundBuffer MedalSound;
    Sound medal;
    Medal_sound(MedalSound, medal);
    //gameloop
    while (window.isOpen()) {
        gameclock.restart();
        //start bird
        if (next == 1) {
            bird.setPosition(247, 233);
            bird.setScale(0.6, 0.6);
        }
        if (next == 2) {

            bird.setScale(0.3, 0.3);
        }
        //choose bird
        if (next == 0) {
            choose(next, chosenBird, Flappy, bird, window, pipeV, groundV, buttonSound, button);

        }
        //play again
        Play_Again(next, restart, window);

        //stop and continue
        if (stop == 0 && next == 2 && Keyboard::isKeyPressed(Keyboard::S)) {

            stop = 1;
            stopp.Stop.setTextureRect(IntRect(47, 0, 47, 47));
            if (VOlume == 1)
                Button_sound(buttonSound, button);
            stopp_Function();

        }


        //continue
        if (stop == 1 && next == 2 && Keyboard::isKeyPressed(Keyboard::C)) {
            stopp.Stop.setTextureRect(IntRect(0, 0, 47, 47));
            if (VOlume == 1)
                Button_sound(buttonSound, button);
            continuee();
            stop = 0;
        }
        // top 3
        Top3menu(next, window, buttonSound, button);
        //top 3 sorting

        top3arrange(next, score);

        //start
        if (next == 1 && (Keyboard::isKeyPressed(Keyboard::Enter))) {
            next = 2;

        }

        //ground move
        if (next == 2) {

            ground_Move(ground);

            sprite_pipesLimit(p.PipeHeight, p2.PipeHeight2, next, increased, increaseLevel, p.topPipeTexture, p.bottomPipeTexture,
                p.topPipe, p.bottomPipe
            );
            movepipes(p.topPipeTexture, p.bottomPipeTexture,
                p.topPipe, p.bottomPipe);

        }
        //game loop
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed)
                window.close();

            //bird move
            if (stop == 0 && next == 2 && Keyboard::isKeyPressed(Keyboard::Space))
            {
                Bird_Move(Flappy, bird, i);
                if (VOlume == 1)
                    Wing_sound(wingSound, Wing);

            }
        }
        if (next == 2) {

            bird.move(0, bird_velocity);
        }
        Bird_Limit(bird, next);



        //collision
        if (next == 2 && (bird.getGlobalBounds().intersects(p2.topPipe.getGlobalBounds())
            || bird.getGlobalBounds().intersects(p2.bottomPipe.getGlobalBounds())
            || bird.getGlobalBounds().intersects(p.topPipe.getGlobalBounds())
            || bird.getGlobalBounds().intersects(p.bottomPipe.getGlobalBounds())))

        {

            Collision(next, bird);
            if (VOlume == 1)
                Hit_sound(hitSound, Hit);

        }
        if (next == 2 && bird.getGlobalBounds().intersects(ground.getGlobalBounds())) {
            Collision(next, bird);

            if (VOlume == 1)
                Die_sound(dieSound, die);
        }


        //score
        if ((next == 2 && bird.getPosition().x > p.topPipe.getPosition().x && bird.getPosition().y > p.topPipe.getPosition().y
            && bird.getPosition().y < p.bottomPipe.getPosition().y && !increased)
            || (next == 2 && bird.getPosition().x > p2.topPipe.getPosition().x
                && bird.getPosition().y > p2.topPipe.getPosition().y &&
                bird.getPosition().y < p2.bottomPipe.getPosition().y) && !increased) {

            score += 1;

            increased = 1;
            if (VOlume == 1)
                Point_sound(pointSound, Point);


        }
        if (score > best_score) {
            best_score = score;
            saveBestScore(best_score);
        }
        // set text to variables
        ourscore.setString("" + to_string(score));
        best.setString("" + to_string(best_score));
        top_3[0].setString("First: " + to_string(Top3[0]));
        top_3[1].setString("Second: " + to_string(Top3[1]));
        top_3[2].setString("Third: " + to_string(Top3[2]));
        //levels
        levels(increaseLevel, bird, next, leveltext, level, levelSound, levell, score);

        //medals
        if (SilverMedalAppear == 1 && level % 2 == 0) {

            Medal = 1;
            medal_silver.setScale(0.14, 0.14);


            SilverMedalAppear = 0;
        }
        else if (SilverMedalAppear == 0 && level != 1 && level % 2 != 0) {


            medal_gold.setScale(0.19, 0.19);
            Medal = 2;

            SilverMedalAppear = 1;
        }

        if (bird.getGlobalBounds().intersects(medal_silver.getGlobalBounds()))
        {
            medal_silver.setScale(0, 0);

            MedalAppear = 1;
            if (VOlume == 1)
                medal.play();
        }
        else if (bird.getGlobalBounds().intersects(medal_gold.getGlobalBounds()))
        {
            medal_gold.setScale(0, 0);

            MedalAppear = 2;
            if (VOlume == 1)
                medal.play();
        }
        //Settings
        if (next == 1) {
            Setting_Choice(next, setting, best_score, window, buttonSound, button);

        }
        // play Again
        if (restart == 1)
        {
            Button_sound(buttonSound, button);
            game();
        }

        window.clear();

        if (next == 0) {
            window.draw(Back.back);
            window.draw(Yellow_Start_Flappy);
            window.draw(Red_Start_Flappy);
            window.draw(choosetext);
            window.draw(Easytext);
            window.draw(Hardtext);
        }
        if (next == 1) {
            window.draw(Back.back);
            window.draw(ready);
            window.draw(tap);
            window.draw(starttext);
            window.draw(settings);
            window.draw(bird);
            if (setting == 1)
            {
                window.draw(all);

                if (setting_choice == 1)
                {
                    window.draw(sound);
                    setting_choice = 0;

                }
                if (setting_choice == 2)
                {
                    window.draw(mute);
                    setting_choice = 0;

                }
                if (setting_choice == 3)
                {
                    window.draw(reset);
                    setting_choice = 0;

                }

            }
        }
        if (next == 2) {
            window.draw(Back.back);

            window.draw(p.topPipe);
            window.draw(p.bottomPipe);
            window.draw(p2.topPipe);
            window.draw(p2.bottomPipe);

            window.draw(ground);
            window.draw(bird);

            window.draw(ourscore);
            window.draw(leveltext);
            window.draw(stopp.Stop);
            if (Medal == 2) {

                medal_gold.setPosition(p.topPipe.getPosition().x + 200, p.topPipe.getPosition().y + 530);
                window.draw(medal_gold);

            }
            else if (Medal == 1) {

                medal_silver.setPosition(p.topPipe.getPosition().x + 200, p.topPipe.getPosition().y + 530);
                window.draw(medal_silver);
            }
        }
        if (next == 3) {
            window.draw(Back.back);

            window.draw(p.topPipe);
            p.topPipe.setPosition(p.topPipe.getPosition().x, p.topPipe.getPosition().y);
            window.draw(p.bottomPipe);
            p.bottomPipe.setPosition(p.bottomPipe.getPosition().x, p.bottomPipe.getPosition().y);
            window.draw(p2.topPipe);
            p2.topPipe.setPosition(p2.topPipe.getPosition().x, p2.topPipe.getPosition().y);
            window.draw(p2.bottomPipe);
            p2.bottomPipe.setPosition(p2.bottomPipe.getPosition().x, p2.bottomPipe.getPosition().y);
            window.draw(ground);
            window.draw(bird);
            window.draw(topp3);
            saveTop3(Top3);
            for (int v = bird_velocity; v > 0; v--) {
                bird.move(0, v);
                die.play();
            }
            window.draw(go);
            window.draw(menu);
            window.draw(again);

            window.draw(ourscore);

            ourscore.setCharacterSize(20);
            ourscore.setPosition(390, 230);
            window.draw(best);
            window.draw(leveltext);

            if (MedalAppear == 1)
            {
                medal_silver.setScale(0.14, 0.14);

                medal_silver.setPosition(187, 245);
                window.draw(medal_silver);
            }
            if (MedalAppear == 2) {

                medal_gold.setScale(0.19, 0.19);
                medal_gold.setPosition(153, 238);
                window.draw(medal_gold);

            }
        }


        if (next == 4) {
            window.draw(Back.back);
            window.draw(back_to);
            for (int i = 0; i < 3; i++) {
                window.draw(top_3[i]);
            }
        }

        window.display();
        delta = gameclock.getElapsedTime().asSeconds();

    }
}
int main() {
    cout << "\n                 * HELLO *        " << "\n\n\n"
        << " Dear player, here are some instructions to help you play." << "\n\n\n"
        << "    1. For the movement of the bird, use the space. " << "\n\n"
        << "    2. To pause, press the s button on the keyboard." << "\n\n"
        << "    3. To continue, press the c button on the keyboard." << "\n\n"
        << "\n               * Enjoy:) *        " << "\n\n\n";
    game();
    return 0;
}