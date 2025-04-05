#include <gui/containers/MessageBoxWindow.hpp>
#include <BitmapDatabase.hpp>

MessageBoxWindow::MessageBoxWindow()
{

}

void MessageBoxWindow::initialize()
{
    MessageBoxWindowBase::initialize();
}

void MessageBoxWindow::OKButton_Execute()
{
    //Close the messageBox
    this->setVisible(false);
	this->invalidate();

    //Set OK Button status
    if(MSGType==MSG_QUESTION)
    {
        OKButtonState =1;   
    }
	
}

void MessageBoxWindow::CancelButton_Execute()
{
	//Close the messageBox
    this->setVisible(false);
	this->invalidate();
}

void MessageBoxWindow::ShowMessageBox (MessageTypeEnum MSG_Type, const char* MsgText)
{
    int x;
    boolean OneButtonFlag; //Only OK button will be displayed 

    MSGType = MSG_Type;

    //Clear OK Button Status
    OKButtonState=0;

    OneButtonFlag=true;

    switch (MSG_Type)
    {
    case MSG_OK:
        MessageIcon.setBitmap(touchgfx::Bitmap(BITMAP_INFOICON_ID));
        break;
    case MSG_ERROR:
        MessageIcon.setBitmap(touchgfx::Bitmap(BITMAP_ERRORICON_ID));
        break;
    case MSG_WARNING:
        MessageIcon.setBitmap(touchgfx::Bitmap(BITMAP_WARNINGICON_ID));
        break;
    case MSG_QUESTION:
        MessageIcon.setBitmap(touchgfx::Bitmap(BITMAP_QUESTIONICON_ID));
        OneButtonFlag=false;
        break;
    }

    if(OneButtonFlag){
        CancelflexButton.setVisible(false);
        x=339;
    }
    else{
        CancelflexButton.setVisible(true);
        x = 251;
    }

    OKflexButton.setXY(x,302);

    Unicode::strncpy(MessageTextBuffer, MsgText, MESSAGETEXT_SIZE);

    this->setVisible(true);
	this->invalidate();

}
