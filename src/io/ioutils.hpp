#ifndef IOUTILS_HPP
#define IOUTILS_HPP

#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QUrl>
#include <functional>

namespace ioutils {
    extern QNetworkAccessManager networkManager;
    void getJson(QUrl target,
                 QList<QPair<QString, QString>> headers,
                 QString filename,
                 std::function<void(QJsonDocument, QByteArray, QNetworkReply *)> callback);
    void postJson(QUrl target,
                  QList<QPair<QString, QString>> headers,
                  QByteArray body,
                  QString filename,
                  std::function<void(QJsonDocument, QByteArray, QNetworkReply *)> callback);
    void getData(QUrl target, QList<QPair<QString, QString>> headers, QString filename, std::function<void(QByteArray, QNetworkReply *)> callback);
    void postData(QUrl target, QList<QPair<QString, QString>> headers, QByteArray body, QString filename, std::function<void(QByteArray, QNetworkReply *)> callback);
    void postMultipart(QUrl target,
                       QList<QPair<QString, QString>> headers,
                       QHttpMultiPart *body,
                       QString filename,
                       std::function<void(QJsonDocument, QByteArray, QNetworkReply *)> callback);
    void postMultipartData(QUrl target,
                           QList<QPair<QString, QString>> headers,
                           QHttpMultiPart *body,
                           QString filename,
                           std::function<void(QByteArray, QNetworkReply *)> callback);
    QString methodString(QNetworkAccessManager::Operation operation);
    QString httpString(int responseCode);
} // namespace ioutils

#endif // IOUTILS_HPP
