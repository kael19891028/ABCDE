#include "GDefine.h"
#include "DTSMainWindow.h"
#include "DTSPageStartup.h"
#include "DTSMessageBox.h"



GERROR ParseCommandLine(QCommandLineParser& parser)
{
    QCommandLineOption opName(QStringList() << STR_APP_CMDLINE_OPTION_N << STR_APP_CMDLINE_OPTION_NAME, STR_APP_CMDLINE_DESC_N, STR_APP_CMDLINE_NAME_N, STR_APP_CMDLINE_DEFAULT_N);
    parser.addOption(opName);

    if (parser.parse(QApplication::arguments()))
    {
        return GERROR_OK;
    }
    qWarning() << STR_MAINTHREAD_BEGIN_CMDLINE_UNKNOWN << parser.unknownOptionNames();
    return GERROR_APP_COMMAND_PARSE;
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setOrganizationName(STR_APP_ORGANIZATIONNAME);
    QApplication::setApplicationName(STR_APP_APPLICATIONNAME);
    QApplication::setApplicationVersion(STR_APP_APPLICATIONVARSION);

    QApplication::setStyle(QStyleFactory::create("Fusion"));

    if (GERROR_OK != qConfig->Initialize()
        || GERROR_OK != qLogger->Initialize())
    {
        qApp->quit();
        return 0;
    }

    QString App_IID;
    if (argc > 1)
    {
        QCommandLineParser parser;
        if (GERROR_OK != ParseCommandLine(parser))
        {
            DTSMessageBox msgBox(DTSMessageBox::EMBTYPE_QUITFORCE);
            msgBox.exec();
        }

        App_IID = parser.value("n");
        qDebug() << STR_MAINTHREAD_BEGIN_CMDLINE_N.arg(App_IID);
    } 
    else
    {
        DTSPageStartup sp;
        sp.exec();

        App_IID = sp.GetAppID();
    }


    DTSMainWindow mainwindow(App_IID);
    if (GERROR_OK != mainwindow.Initialize())
    {
        qApp->quit();
        return 0;
    }

    mainwindow.show();

 
    return app.exec();
}
