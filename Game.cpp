#include "Game.h"

//Static functions



//Initialize functions

void Game::initWindow()
{
    std::ifstream ifs("Config/window.txt");
    std::string title = "none";
    window_bounds.width = 800;
    window_bounds.height = 600;
    unsigned framerate_limit = 60;
    bool vertical_sync_enabled = false;
    settings.antialiasingLevel = 8;

    //this->view.setSize(sf::Vector2f(300.0f,300.0f));



    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(window_bounds, title);
    
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
    

}

Game::Game()
{
    

    this->initWindow();

    this->font.loadFromFile("Textures/28 Days Later.ttf");
    this->screenFont.loadFromFile("Textures/data-latin.ttf");

    this->initLoadingScreen();

    this->wind = this->window;
    
}

Game::~Game()
{
    delete this->startGameBTN;

   
    

	delete this->window;
    
}


//Functions

void Game::dtFrameTime()
{
    this->dt = this->dtTime.restart().asSeconds();
    system("cls");
    std::cout << this->dt << std::endl;
    std::cout <<"Frames per second: "<<1/this->dt << std::endl;
  
}

void Game::timeUpdate()
{
    this->time = this->gameTime.getElapsedTime().asMilliseconds();
    this->time =this->time / 1000;
    this->screenText.setString(std::to_string(this->time) + "s");
}

void Game::renderScreenText(sf::Text screenText)
{
    this->window->draw(screenText);
}

void Game::initScreenText(float x, float y,std::string text,int size)
{
    this->screenText.setString(text);
    this->screenText.setCharacterSize(size);
    this->screenText.setFont(this->screenFont);
    this->screenText.setPosition(x, y);
}

void Game::initLoadingScreen()
{
    this->loadingScreen.setFillColor(sf::Color::Black);
    this->loadingScreen.setSize(sf::Vector2f(this->window->getSize()));
    this->loadingScreen.setPosition(0, 0);
    
    this->screenText.setFillColor(sf::Color::White);
    this->screenText.setString("Loading Please Wait");
    this->screenText.setFont(font);
    this->screenText.setCharacterSize(150);
    
    this->screenText.setPosition(this->window_bounds.width/8, this->window_bounds.height/3);
}

void Game::renderLoadingScreen()
{
    
    this->window->draw(this->loadingScreen);
    this->window->draw(this->screenText);
}

void Game::updateAgents()
{
    //update and move every agent
    for (int k = 0; k < agents_g.size(); k++)
    {
        this->agents_o[k]->move(this->window);
        this->agents_g[k]->update(this->agents_o[k]);
    }
    //adds new agent
    if (this->time > this->addAgentTime)
    {
        for (int i = 0; i < 2; i++)
        {
            this->pomAgent = new CAgent(this->window);
            this->pomGAgent = new CGAgent(this->pomAgent);

            this->agents_o.push_back(this->pomAgent);
            this->agents_g.push_back(this->pomGAgent);
        }

        this->addAgentTime += 5;
    }
    //changes direction of the agents
    if (this->time > this->changeDirTime)
    {
        for (int i = 0; i < this->agents_o.size(); i++)
        {
            this->agents_o[i]->setDir();
        }
        this->changeDirTime += 10;
    }

}

void Game::checkAgentCollision()
{
    for (int i = 0; i < this->agents_o.size(); i++)
    {
        if (this->agents_o[i]->checkIfInRange(this->player))
        {
            Sleep(1000);
            this->window->clear();
            this->window->setView(this->window->getDefaultView());
            this->initScreenText(100, this->window_bounds.height / 2 - 100, "You survived " + std::to_string(this->time) + " seconds.", 100);
            this->renderScreenText(this->screenText);
            this->window->display();
            Sleep(4000);
            this->gameWindowState = MAIN_MENU;
        }


    }
    //this->view.setSize(sf::Vector2f(1280, 950));
   // this->view.setCenter(sf::Vector2f(this->window_bounds.width / 2, this->window_bounds.height / 2));
    //this->window->getDefaultView();
    
 }

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->SFevent))
    {
        switch (this->SFevent.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->SFevent.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

void Game::updateMousePos()
{
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void Game::updatePlayerMove()
{
    this->m_object->move(this->window);

      
    
}

void Game::update()
{
    this->checkAgentCollision();

    this->updateSFMLEvents();
    
    this->updatePlayerMove();

    this->timeUpdate();

    //agent update
    this->updateAgents();
    //-agent update

    //check agent collision
    
    //-check agent collision

    //check map collisions


    //-check map collisions      



    
}

void Game::render()
{
        this->window->clear();
 
        this->window->setView(view);
        this->window->getDefaultView();
        
        this->view.setSize(sf::Vector2f(900.0f, 450.0f));
        this->view.setCenter(this->player->position_x, this->player->position_y);

        this->map->render(this->window);
        this->gplayer->update_render(this->player, window);
        this->renderScreenText(this->screenText);
        //agent render
        for (int k = 0; k < agents_g.size(); k++)
        {
            this->agents_g[k]->render(this->window);
        }
        //-agent render        
        this->window->display();

        
        
}

void Game::run()
{

    /*while (true)
    {
        dtFrameTime();
    }*/

    this->gameWindowState = MAIN_MENU;
    CMainMenu mainmenu;
    while (this->gameWindowState != EXIT)
    {

        switch (this->gameWindowState)
        {
        case MAIN_MENU:
            this->window->setSize(sf::Vector2u(1280, 950));

            this->window->setView(this->window->getDefaultView());
            

            while (mainmenu.exitGameBTN->isPressed()==false && mainmenu.startGameBTN->isPressed() == false)
            {
                this->window->clear();

                //
                mainmenu.initMainMenu(this->window);
                updateMousePos();

                mainmenu.startGameBTN->update(mousePosView);
                mainmenu.exitGameBTN->update(mousePosView);
                mainmenu.optionsGameBTN->update(mousePosView);

                mainmenu.startGameBTN->render(this->window);
                mainmenu.exitGameBTN->render(this->window);
                mainmenu.optionsGameBTN->render(this->window);

                dtFrameTime();
                this->updateSFMLEvents();
                //

                this->window->display();
                
                
            }
            if (mainmenu.exitGameBTN->isPressed() == true)
            {
                this->gameWindowState = EXIT;
            }
            else if (mainmenu.startGameBTN->isPressed() == true)
            {
                this->gameWindowState = PLAY_GAME;
            }
            mainmenu.exitGameBTN->buttonState = 0;
            mainmenu.startGameBTN->buttonState = 0;

            break;
        case EXIT:
            this->window->close();
            break;
        case GAME_OPTIONS:
            break;
        case PLAY_GAME:

            this->addAgentTime = 7;
            this->changeDirTime = 5;

            this->ammountOfStartAgents = 20;

           //loading screen
           this->window->setSize(sf::Vector2u(window_bounds.width, window_bounds.height));

           this->initLoadingScreen();
           this->window->clear();
           this->renderLoadingScreen();
           this->window->display();
           //-loading screen

           //load map
           this->map = new CMap();
           this->map->createRandomMap();
           //-load map

           //create player
            CPlayer player1(5.f, 15.f);

            player1.position_x = window_bounds.width / 2;
            player1.position_y = window_bounds.height / 2;

            this->player = &player1;
            CGPlayer gPlayer(this->player);
            this->gplayer = &gPlayer;
            this->m_object = &player1;
            //-create player

            //create agents

            for (int k = 0; k < this->ammountOfStartAgents; k++)
            {
                this->pomAgent = new CAgent(this->window);
                this->pomGAgent = new CGAgent(this->pomAgent);

                this->agents_o.push_back(this->pomAgent);
                this->agents_g.push_back(this->pomGAgent);
            }

            //-create agents

            //check time
            
            this->time = this->gameTime.restart().asMilliseconds();
            this->initScreenText(0, 0, std::to_string(this->time) + "s", 50);
            //-check time

            //game loop
            while (this->window->isOpen() && this->gameWindowState == PLAY_GAME)
            {
                dtFrameTime();

                this->render();
                
                this->update();

                //game over
                if (this->gameWindowState == MAIN_MENU )
                {
                    //this->view.setSize(sf::Vector2f(1280, 950));
                    //this->view.setCenter(this->window_bounds.width/2, this->window_bounds.height/2);

                    for (int i = 0; i < agents_o.size(); i++)
                    {

                        delete this->agents_g[i];
                        delete this->agents_o[i];

                    } 
                    agents_g.clear();
                    agents_o.clear();

                    

                    break;
                }
                //game over
            }
            //-game loop
            
            
            break;
        }
    }
    
}
