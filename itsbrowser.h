#ifndef ITSBROWSER_H
#define ITSBROWSER_H

#include <QWebView>
#include <QNetworkCookieJar>
#include "qdebug.h"
#include <QSslError>
#include <QNetworkReply>
#include <QMessageBox>
#include <QDialog>
#include <QLineEdit>
#include <QInputDialog>
#include <QAuthenticator>
#include <QWebFrame>
#include <QNetworkProxy>

class itsBrowser : public QWebView
{
    Q_OBJECT
public:
    explicit itsBrowser(QWidget *parent = 0);
    int getInblrMark(QString);
    void setInblrMark(QString,int);
    void setInblrMarkAllZero();
    void setInblrMarkZero();
    bool InblrContainsStuNum(QString);
    void setInblrCanBlackOut();

signals:
    void onAnyError(QString);
public slots:
    void handleSslErrors(QNetworkReply* reply, const QList<QSslError> &errors);
    void provideAuthentication(QNetworkReply*,QAuthenticator*);
    void provideProxAuthentication(const QNetworkProxy &, QAuthenticator*);

};

#endif // ITSBROWSER_H
