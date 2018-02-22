#ifndef VIEW
#define VIEW

#include <QWebView>
#include <QWebPage>
#include <QWidget>

class View : public QWebView
{
    Q_OBJECT

    public:
        View(QWidget* parent);
        void loadPage(QString uri);
        void loadImage(QString uri);

    private slots:
        void handleAuthRequest(QNetworkReply*, QAuthenticator*);
};


#endif // VIEW
