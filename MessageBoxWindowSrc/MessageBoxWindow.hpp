#ifndef MESSAGEBOXWINDOW_HPP
#define MESSAGEBOXWINDOW_HPP

#include <gui_generated/containers/MessageBoxWindowBase.hpp>

typedef enum
{
    MSG_OK,
    MSG_ERROR,
    MSG_WARNING,
    MSG_QUESTION
}MessageTypeEnum;

class MessageBoxWindow : public MessageBoxWindowBase
{
public:
    char OKButtonState;
    MessageBoxWindow();
    virtual ~MessageBoxWindow() {}

    virtual void initialize();
    virtual void OKButton_Execute();
    virtual void CancelButton_Execute();
    virtual void ShowMessageBox (MessageTypeEnum MSG_Type, const char* MsgText);
protected:
    MessageTypeEnum MSGType;
};

#endif // MESSAGEBOXWINDOW_HPP
