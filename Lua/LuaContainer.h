#ifndef LUACONTAINER_H
#define LUACONTAINER_H

#include <QSettings>
#include <QString>

#include "LuaEvent.h"

class LuaCode;
class LuaConfig;

class LuaContainer
{
public:
    LuaContainer();
    LuaContainer(LuaCode* luacode);
    LuaContainer(LuaCode* luacode, LuaConfig* luaconfig);
    ~LuaContainer();

    QString getCode();
    QString getDesc();
    QString getName();

    bool isTriggered(const LuaEvent& event);

    void setCode(const QString& code);
    void setCode(const std::string& code);
    void setDesc(const QString& desc);
    void setDesc(const std::string& desc);
    void setName(const QString& name);
    void setName(const std::string& name);

    void getSettings(QSettings& settings);
    void loadSettings(QSettings& settings);

    bool getEnabled();
    void setEnabled(const bool enable);

    QDateTime getLastTriggered();
    void setLastTriggered(const QDateTime& dt);

    bool getConstraintEnabled();
    void setConstraintEnabled(const bool enable);

    void getConstraintFromTo(QTime& from, QTime& to);
    void setConstraintFromTo(const QTime& from, const QTime& to);


    void setRunEveryChecked(bool checked);
    bool getRunEveryChecked();

    void setRunOnceChecked(bool checked, QDateTime when);
    bool getRunOnceChecked();

    void setRunStartupChecked(bool checked);
    bool getRunStartupChecked();

    void setRunShutdownChecked(bool checked);
    bool getRunShutdownChecked();


private:
    LuaCode* _code;
    LuaConfig* _config ;
};

#endif // LUACONTAINER_H
