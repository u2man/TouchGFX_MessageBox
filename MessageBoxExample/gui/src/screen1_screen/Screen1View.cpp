#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::handleTickEvent()
{
    if(messageBoxWindow.OKButtonState){
        messageBoxWindow.ShowMessageBox(MSG_OK,"You click OK Button"); 
        messageBoxWindow.OKButtonState=0;
    }

}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::ShowOKMessage()
{
    messageBoxWindow.ShowMessageBox(MSG_OK,"Message OK");
}

void Screen1View::ShowERRORMessage()
{
    messageBoxWindow.ShowMessageBox(MSG_ERROR,"Message ERROR");
}

void Screen1View::ShowWARNINGMessage()
{
    messageBoxWindow.ShowMessageBox(MSG_WARNING,"Message WARNING");
}

void Screen1View::ShowQUESTIONMessage()
{
    messageBoxWindow.ShowMessageBox(MSG_QUESTION,"Are you sure to exit?");
}
