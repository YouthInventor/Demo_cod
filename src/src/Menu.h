#pragma once

enum class Page {
    Overview = 0,
    StopWatch = 1,
    Results= 2,
    Others =3,
};

class Menu {
public:
    void setup();
    void next();
    void previous();
    void select();
    Page currentPage();
    Page currentSelectedPage();
    int currentColor();

private: //methods
    void nextOverview();
    void prevOverview();
    void selectOverview();
    
    void nextColor();
    void prevColor();

private:
    Page m_currentPage; // Current page which is shown int current page
    Page m_currentSelectedPage; // Page which is selected while in overview page
    int m_currentColor;
};