// +build !minimal

#define protected public
#define private public

#include "websockets.h"
#include "_cgo_export.h"

#include <QAbstractSocket>
#include <QAuthenticator>
#include <QByteArray>
#include <QChildEvent>
#include <QEvent>
#include <QHostAddress>
#include <QMaskGenerator>
#include <QMetaMethod>
#include <QMetaObject>
#include <QNetworkProxy>
#include <QNetworkRequest>
#include <QObject>
#include <QSslConfiguration>
#include <QSslError>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QTimerEvent>
#include <QUrl>
#include <QWebSocket>
#include <QWebSocketCorsAuthenticator>
#include <QWebSocketServer>

class MyQMaskGenerator: public QMaskGenerator
{
public:
	MyQMaskGenerator(QObject *parent) : QMaskGenerator(parent) {};
	quint32 nextMask() { return callbackQMaskGenerator_NextMask(this); };
	bool seed() { return callbackQMaskGenerator_Seed(this) != 0; };
	 ~MyQMaskGenerator() { callbackQMaskGenerator_DestroyQMaskGenerator(this); };
	void timerEvent(QTimerEvent * event) { callbackQMaskGenerator_TimerEvent(this, event); };
	void childEvent(QChildEvent * event) { callbackQMaskGenerator_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackQMaskGenerator_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackQMaskGenerator_CustomEvent(this, event); };
	void deleteLater() { callbackQMaskGenerator_DeleteLater(this); };
	void disconnectNotify(const QMetaMethod & sign) { callbackQMaskGenerator_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	bool event(QEvent * e) { return callbackQMaskGenerator_Event(this, e) != 0; };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackQMaskGenerator_EventFilter(this, watched, event) != 0; };
	const QMetaObject * metaObject() const { return static_cast<QMetaObject*>(callbackQMaskGenerator_MetaObject(const_cast<MyQMaskGenerator*>(this))); };
};

void* QMaskGenerator_NewQMaskGenerator(void* parent)
{
	return new MyQMaskGenerator(static_cast<QObject*>(parent));
}

unsigned int QMaskGenerator_NextMask(void* ptr)
{
	return static_cast<QMaskGenerator*>(ptr)->nextMask();
}

char QMaskGenerator_Seed(void* ptr)
{
	return static_cast<QMaskGenerator*>(ptr)->seed();
}

void QMaskGenerator_DestroyQMaskGenerator(void* ptr)
{
	static_cast<QMaskGenerator*>(ptr)->~QMaskGenerator();
}

void QMaskGenerator_DestroyQMaskGeneratorDefault(void* ptr)
{

}

void QMaskGenerator_TimerEvent(void* ptr, void* event)
{
	static_cast<QMaskGenerator*>(ptr)->timerEvent(static_cast<QTimerEvent*>(event));
}

void QMaskGenerator_TimerEventDefault(void* ptr, void* event)
{
	static_cast<QMaskGenerator*>(ptr)->QMaskGenerator::timerEvent(static_cast<QTimerEvent*>(event));
}

void QMaskGenerator_ChildEvent(void* ptr, void* event)
{
	static_cast<QMaskGenerator*>(ptr)->childEvent(static_cast<QChildEvent*>(event));
}

void QMaskGenerator_ChildEventDefault(void* ptr, void* event)
{
	static_cast<QMaskGenerator*>(ptr)->QMaskGenerator::childEvent(static_cast<QChildEvent*>(event));
}

void QMaskGenerator_ConnectNotify(void* ptr, void* sign)
{
	static_cast<QMaskGenerator*>(ptr)->connectNotify(*static_cast<QMetaMethod*>(sign));
}

void QMaskGenerator_ConnectNotifyDefault(void* ptr, void* sign)
{
	static_cast<QMaskGenerator*>(ptr)->QMaskGenerator::connectNotify(*static_cast<QMetaMethod*>(sign));
}

void QMaskGenerator_CustomEvent(void* ptr, void* event)
{
	static_cast<QMaskGenerator*>(ptr)->customEvent(static_cast<QEvent*>(event));
}

void QMaskGenerator_CustomEventDefault(void* ptr, void* event)
{
	static_cast<QMaskGenerator*>(ptr)->QMaskGenerator::customEvent(static_cast<QEvent*>(event));
}

void QMaskGenerator_DeleteLater(void* ptr)
{
	QMetaObject::invokeMethod(static_cast<QMaskGenerator*>(ptr), "deleteLater");
}

void QMaskGenerator_DeleteLaterDefault(void* ptr)
{
	static_cast<QMaskGenerator*>(ptr)->QMaskGenerator::deleteLater();
}

void QMaskGenerator_DisconnectNotify(void* ptr, void* sign)
{
	static_cast<QMaskGenerator*>(ptr)->disconnectNotify(*static_cast<QMetaMethod*>(sign));
}

void QMaskGenerator_DisconnectNotifyDefault(void* ptr, void* sign)
{
	static_cast<QMaskGenerator*>(ptr)->QMaskGenerator::disconnectNotify(*static_cast<QMetaMethod*>(sign));
}

char QMaskGenerator_Event(void* ptr, void* e)
{
	return static_cast<QMaskGenerator*>(ptr)->event(static_cast<QEvent*>(e));
}

char QMaskGenerator_EventDefault(void* ptr, void* e)
{
	return static_cast<QMaskGenerator*>(ptr)->QMaskGenerator::event(static_cast<QEvent*>(e));
}

char QMaskGenerator_EventFilter(void* ptr, void* watched, void* event)
{
	return static_cast<QMaskGenerator*>(ptr)->eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
}

char QMaskGenerator_EventFilterDefault(void* ptr, void* watched, void* event)
{
	return static_cast<QMaskGenerator*>(ptr)->QMaskGenerator::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
}

void* QMaskGenerator_MetaObject(void* ptr)
{
	return const_cast<QMetaObject*>(static_cast<QMaskGenerator*>(ptr)->metaObject());
}

void* QMaskGenerator_MetaObjectDefault(void* ptr)
{
	return const_cast<QMetaObject*>(static_cast<QMaskGenerator*>(ptr)->QMaskGenerator::metaObject());
}

class MyQWebSocket: public QWebSocket
{
public:
	void Signal_AboutToClose() { callbackQWebSocket_AboutToClose(this); };
	void Signal_BinaryFrameReceived(const QByteArray & frame, bool isLastFrame) { callbackQWebSocket_BinaryFrameReceived(this, const_cast<char*>(frame.toHex().prepend("WHITESPACE").constData()+10), isLastFrame); };
	void Signal_BinaryMessageReceived(const QByteArray & message) { callbackQWebSocket_BinaryMessageReceived(this, const_cast<char*>(message.toHex().prepend("WHITESPACE").constData()+10)); };
	void Signal_BytesWritten(qint64 bytes) { callbackQWebSocket_BytesWritten(this, bytes); };
	void Signal_Connected() { callbackQWebSocket_Connected(this); };
	void Signal_Disconnected() { callbackQWebSocket_Disconnected(this); };
	void Signal_Error2(QAbstractSocket::SocketError error) { callbackQWebSocket_Error2(this, error); };
	void ignoreSslErrors() { callbackQWebSocket_IgnoreSslErrors(this); };
	void open(const QNetworkRequest & request) { callbackQWebSocket_Open2(this, const_cast<QNetworkRequest*>(&request)); };
	void open(const QUrl & url) { callbackQWebSocket_Open(this, const_cast<QUrl*>(&url)); };
	void ping(const QByteArray & payload) { callbackQWebSocket_Ping(this, const_cast<char*>(payload.toHex().prepend("WHITESPACE").constData()+10)); };
	void Signal_Pong(quint64 elapsedTime, const QByteArray & payload) { callbackQWebSocket_Pong(this, elapsedTime, const_cast<char*>(payload.toHex().prepend("WHITESPACE").constData()+10)); };
	void Signal_ProxyAuthenticationRequired(const QNetworkProxy & proxy, QAuthenticator * authenticator) { callbackQWebSocket_ProxyAuthenticationRequired(this, const_cast<QNetworkProxy*>(&proxy), authenticator); };
	void Signal_ReadChannelFinished() { callbackQWebSocket_ReadChannelFinished(this); };
	void Signal_StateChanged(QAbstractSocket::SocketState state) { callbackQWebSocket_StateChanged(this, state); };
	void Signal_TextFrameReceived(const QString & frame, bool isLastFrame) { callbackQWebSocket_TextFrameReceived(this, const_cast<char*>(frame.toUtf8().prepend("WHITESPACE").constData()+10), isLastFrame); };
	void Signal_TextMessageReceived(const QString & message) { callbackQWebSocket_TextMessageReceived(this, const_cast<char*>(message.toUtf8().prepend("WHITESPACE").constData()+10)); };
	 ~MyQWebSocket() { callbackQWebSocket_DestroyQWebSocket(this); };
	void timerEvent(QTimerEvent * event) { callbackQWebSocket_TimerEvent(this, event); };
	void childEvent(QChildEvent * event) { callbackQWebSocket_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackQWebSocket_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackQWebSocket_CustomEvent(this, event); };
	void deleteLater() { callbackQWebSocket_DeleteLater(this); };
	void disconnectNotify(const QMetaMethod & sign) { callbackQWebSocket_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	bool event(QEvent * e) { return callbackQWebSocket_Event(this, e) != 0; };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackQWebSocket_EventFilter(this, watched, event) != 0; };
	const QMetaObject * metaObject() const { return static_cast<QMetaObject*>(callbackQWebSocket_MetaObject(const_cast<MyQWebSocket*>(this))); };
};

void QWebSocket_Abort(void* ptr)
{
	static_cast<QWebSocket*>(ptr)->abort();
}

void QWebSocket_ConnectAboutToClose(void* ptr)
{
	QObject::connect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)()>(&QWebSocket::aboutToClose), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)()>(&MyQWebSocket::Signal_AboutToClose));
}

void QWebSocket_DisconnectAboutToClose(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)()>(&QWebSocket::aboutToClose), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)()>(&MyQWebSocket::Signal_AboutToClose));
}

void QWebSocket_AboutToClose(void* ptr)
{
	static_cast<QWebSocket*>(ptr)->aboutToClose();
}

void QWebSocket_ConnectBinaryFrameReceived(void* ptr)
{
	QObject::connect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(const QByteArray &, bool)>(&QWebSocket::binaryFrameReceived), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(const QByteArray &, bool)>(&MyQWebSocket::Signal_BinaryFrameReceived));
}

void QWebSocket_DisconnectBinaryFrameReceived(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(const QByteArray &, bool)>(&QWebSocket::binaryFrameReceived), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(const QByteArray &, bool)>(&MyQWebSocket::Signal_BinaryFrameReceived));
}

void QWebSocket_BinaryFrameReceived(void* ptr, char* frame, char isLastFrame)
{
	static_cast<QWebSocket*>(ptr)->binaryFrameReceived(QByteArray::fromHex(QString(frame).toUtf8()), isLastFrame != 0);
}

void QWebSocket_ConnectBinaryMessageReceived(void* ptr)
{
	QObject::connect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(const QByteArray &)>(&QWebSocket::binaryMessageReceived), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(const QByteArray &)>(&MyQWebSocket::Signal_BinaryMessageReceived));
}

void QWebSocket_DisconnectBinaryMessageReceived(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(const QByteArray &)>(&QWebSocket::binaryMessageReceived), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(const QByteArray &)>(&MyQWebSocket::Signal_BinaryMessageReceived));
}

void QWebSocket_BinaryMessageReceived(void* ptr, char* message)
{
	static_cast<QWebSocket*>(ptr)->binaryMessageReceived(QByteArray::fromHex(QString(message).toUtf8()));
}

void QWebSocket_ConnectBytesWritten(void* ptr)
{
	QObject::connect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(qint64)>(&QWebSocket::bytesWritten), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(qint64)>(&MyQWebSocket::Signal_BytesWritten));
}

void QWebSocket_DisconnectBytesWritten(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(qint64)>(&QWebSocket::bytesWritten), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(qint64)>(&MyQWebSocket::Signal_BytesWritten));
}

void QWebSocket_BytesWritten(void* ptr, long long bytes)
{
	static_cast<QWebSocket*>(ptr)->bytesWritten(bytes);
}

char* QWebSocket_CloseReason(void* ptr)
{
	return const_cast<char*>(static_cast<QWebSocket*>(ptr)->closeReason().toUtf8().prepend("WHITESPACE").constData()+10);
}

void QWebSocket_ConnectConnected(void* ptr)
{
	QObject::connect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)()>(&QWebSocket::connected), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)()>(&MyQWebSocket::Signal_Connected));
}

void QWebSocket_DisconnectConnected(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)()>(&QWebSocket::connected), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)()>(&MyQWebSocket::Signal_Connected));
}

void QWebSocket_Connected(void* ptr)
{
	static_cast<QWebSocket*>(ptr)->connected();
}

void QWebSocket_ConnectDisconnected(void* ptr)
{
	QObject::connect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)()>(&QWebSocket::disconnected), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)()>(&MyQWebSocket::Signal_Disconnected));
}

void QWebSocket_DisconnectDisconnected(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)()>(&QWebSocket::disconnected), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)()>(&MyQWebSocket::Signal_Disconnected));
}

void QWebSocket_Disconnected(void* ptr)
{
	static_cast<QWebSocket*>(ptr)->disconnected();
}

void QWebSocket_ConnectError2(void* ptr)
{
	QObject::connect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(QAbstractSocket::SocketError)>(&QWebSocket::error), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(QAbstractSocket::SocketError)>(&MyQWebSocket::Signal_Error2));
}

void QWebSocket_DisconnectError2(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(QAbstractSocket::SocketError)>(&QWebSocket::error), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(QAbstractSocket::SocketError)>(&MyQWebSocket::Signal_Error2));
}

void QWebSocket_Error2(void* ptr, long long error)
{
	static_cast<QWebSocket*>(ptr)->error(static_cast<QAbstractSocket::SocketError>(error));
}

long long QWebSocket_Error(void* ptr)
{
	return static_cast<QWebSocket*>(ptr)->error();
}

char* QWebSocket_ErrorString(void* ptr)
{
	return const_cast<char*>(static_cast<QWebSocket*>(ptr)->errorString().toUtf8().prepend("WHITESPACE").constData()+10);
}

char QWebSocket_Flush(void* ptr)
{
	return static_cast<QWebSocket*>(ptr)->flush();
}

void QWebSocket_IgnoreSslErrors(void* ptr)
{
	QMetaObject::invokeMethod(static_cast<QWebSocket*>(ptr), "ignoreSslErrors");
}

char QWebSocket_IsValid(void* ptr)
{
	return static_cast<QWebSocket*>(ptr)->isValid();
}

void* QWebSocket_LocalAddress(void* ptr)
{
	return new QHostAddress(static_cast<QWebSocket*>(ptr)->localAddress());
}

unsigned short QWebSocket_LocalPort(void* ptr)
{
	return static_cast<QWebSocket*>(ptr)->localPort();
}

void* QWebSocket_MaskGenerator(void* ptr)
{
	return const_cast<QMaskGenerator*>(static_cast<QWebSocket*>(ptr)->maskGenerator());
}

void QWebSocket_Open2(void* ptr, void* request)
{
	QMetaObject::invokeMethod(static_cast<QWebSocket*>(ptr), "open", Q_ARG(QNetworkRequest, *static_cast<QNetworkRequest*>(request)));
}

void QWebSocket_Open(void* ptr, void* url)
{
	QMetaObject::invokeMethod(static_cast<QWebSocket*>(ptr), "open", Q_ARG(QUrl, *static_cast<QUrl*>(url)));
}

char* QWebSocket_Origin(void* ptr)
{
	return const_cast<char*>(static_cast<QWebSocket*>(ptr)->origin().toUtf8().prepend("WHITESPACE").constData()+10);
}

long long QWebSocket_PauseMode(void* ptr)
{
	return static_cast<QWebSocket*>(ptr)->pauseMode();
}

void* QWebSocket_PeerAddress(void* ptr)
{
	return new QHostAddress(static_cast<QWebSocket*>(ptr)->peerAddress());
}

char* QWebSocket_PeerName(void* ptr)
{
	return const_cast<char*>(static_cast<QWebSocket*>(ptr)->peerName().toUtf8().prepend("WHITESPACE").constData()+10);
}

unsigned short QWebSocket_PeerPort(void* ptr)
{
	return static_cast<QWebSocket*>(ptr)->peerPort();
}

void QWebSocket_Ping(void* ptr, char* payload)
{
	QMetaObject::invokeMethod(static_cast<QWebSocket*>(ptr), "ping", Q_ARG(QByteArray, QByteArray::fromHex(QString(payload).toUtf8())));
}

void QWebSocket_ConnectPong(void* ptr)
{
	QObject::connect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(quint64, const QByteArray &)>(&QWebSocket::pong), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(quint64, const QByteArray &)>(&MyQWebSocket::Signal_Pong));
}

void QWebSocket_DisconnectPong(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(quint64, const QByteArray &)>(&QWebSocket::pong), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(quint64, const QByteArray &)>(&MyQWebSocket::Signal_Pong));
}

void QWebSocket_Pong(void* ptr, unsigned long long elapsedTime, char* payload)
{
	static_cast<QWebSocket*>(ptr)->pong(elapsedTime, QByteArray::fromHex(QString(payload).toUtf8()));
}

void* QWebSocket_Proxy(void* ptr)
{
	return new QNetworkProxy(static_cast<QWebSocket*>(ptr)->proxy());
}

void QWebSocket_ConnectProxyAuthenticationRequired(void* ptr)
{
	QObject::connect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(const QNetworkProxy &, QAuthenticator *)>(&QWebSocket::proxyAuthenticationRequired), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(const QNetworkProxy &, QAuthenticator *)>(&MyQWebSocket::Signal_ProxyAuthenticationRequired));
}

void QWebSocket_DisconnectProxyAuthenticationRequired(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(const QNetworkProxy &, QAuthenticator *)>(&QWebSocket::proxyAuthenticationRequired), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(const QNetworkProxy &, QAuthenticator *)>(&MyQWebSocket::Signal_ProxyAuthenticationRequired));
}

void QWebSocket_ProxyAuthenticationRequired(void* ptr, void* proxy, void* authenticator)
{
	static_cast<QWebSocket*>(ptr)->proxyAuthenticationRequired(*static_cast<QNetworkProxy*>(proxy), static_cast<QAuthenticator*>(authenticator));
}

long long QWebSocket_ReadBufferSize(void* ptr)
{
	return static_cast<QWebSocket*>(ptr)->readBufferSize();
}

void QWebSocket_ConnectReadChannelFinished(void* ptr)
{
	QObject::connect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)()>(&QWebSocket::readChannelFinished), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)()>(&MyQWebSocket::Signal_ReadChannelFinished));
}

void QWebSocket_DisconnectReadChannelFinished(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)()>(&QWebSocket::readChannelFinished), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)()>(&MyQWebSocket::Signal_ReadChannelFinished));
}

void QWebSocket_ReadChannelFinished(void* ptr)
{
	static_cast<QWebSocket*>(ptr)->readChannelFinished();
}

void* QWebSocket_Request(void* ptr)
{
	return new QNetworkRequest(static_cast<QWebSocket*>(ptr)->request());
}

void* QWebSocket_RequestUrl(void* ptr)
{
	return new QUrl(static_cast<QWebSocket*>(ptr)->requestUrl());
}

char* QWebSocket_ResourceName(void* ptr)
{
	return const_cast<char*>(static_cast<QWebSocket*>(ptr)->resourceName().toUtf8().prepend("WHITESPACE").constData()+10);
}

void QWebSocket_Resume(void* ptr)
{
	static_cast<QWebSocket*>(ptr)->resume();
}

long long QWebSocket_SendBinaryMessage(void* ptr, char* data)
{
	return static_cast<QWebSocket*>(ptr)->sendBinaryMessage(QByteArray::fromHex(QString(data).toUtf8()));
}

long long QWebSocket_SendTextMessage(void* ptr, char* message)
{
	return static_cast<QWebSocket*>(ptr)->sendTextMessage(QString(message));
}

void QWebSocket_SetMaskGenerator(void* ptr, void* maskGenerator)
{
	static_cast<QWebSocket*>(ptr)->setMaskGenerator(static_cast<QMaskGenerator*>(maskGenerator));
}

void QWebSocket_SetPauseMode(void* ptr, long long pauseMode)
{
	static_cast<QWebSocket*>(ptr)->setPauseMode(static_cast<QAbstractSocket::PauseMode>(pauseMode));
}

void QWebSocket_SetProxy(void* ptr, void* networkProxy)
{
	static_cast<QWebSocket*>(ptr)->setProxy(*static_cast<QNetworkProxy*>(networkProxy));
}

void QWebSocket_SetReadBufferSize(void* ptr, long long size)
{
	static_cast<QWebSocket*>(ptr)->setReadBufferSize(size);
}

void QWebSocket_SetSslConfiguration(void* ptr, void* sslConfiguration)
{
	static_cast<QWebSocket*>(ptr)->setSslConfiguration(*static_cast<QSslConfiguration*>(sslConfiguration));
}

void* QWebSocket_SslConfiguration(void* ptr)
{
	return new QSslConfiguration(static_cast<QWebSocket*>(ptr)->sslConfiguration());
}

long long QWebSocket_State(void* ptr)
{
	return static_cast<QWebSocket*>(ptr)->state();
}

void QWebSocket_ConnectStateChanged(void* ptr)
{
	QObject::connect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(QAbstractSocket::SocketState)>(&QWebSocket::stateChanged), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(QAbstractSocket::SocketState)>(&MyQWebSocket::Signal_StateChanged));
}

void QWebSocket_DisconnectStateChanged(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(QAbstractSocket::SocketState)>(&QWebSocket::stateChanged), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(QAbstractSocket::SocketState)>(&MyQWebSocket::Signal_StateChanged));
}

void QWebSocket_StateChanged(void* ptr, long long state)
{
	static_cast<QWebSocket*>(ptr)->stateChanged(static_cast<QAbstractSocket::SocketState>(state));
}

void QWebSocket_ConnectTextFrameReceived(void* ptr)
{
	QObject::connect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(const QString &, bool)>(&QWebSocket::textFrameReceived), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(const QString &, bool)>(&MyQWebSocket::Signal_TextFrameReceived));
}

void QWebSocket_DisconnectTextFrameReceived(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(const QString &, bool)>(&QWebSocket::textFrameReceived), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(const QString &, bool)>(&MyQWebSocket::Signal_TextFrameReceived));
}

void QWebSocket_TextFrameReceived(void* ptr, char* frame, char isLastFrame)
{
	static_cast<QWebSocket*>(ptr)->textFrameReceived(QString(frame), isLastFrame != 0);
}

void QWebSocket_ConnectTextMessageReceived(void* ptr)
{
	QObject::connect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(const QString &)>(&QWebSocket::textMessageReceived), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(const QString &)>(&MyQWebSocket::Signal_TextMessageReceived));
}

void QWebSocket_DisconnectTextMessageReceived(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocket*>(ptr), static_cast<void (QWebSocket::*)(const QString &)>(&QWebSocket::textMessageReceived), static_cast<MyQWebSocket*>(ptr), static_cast<void (MyQWebSocket::*)(const QString &)>(&MyQWebSocket::Signal_TextMessageReceived));
}

void QWebSocket_TextMessageReceived(void* ptr, char* message)
{
	static_cast<QWebSocket*>(ptr)->textMessageReceived(QString(message));
}

void QWebSocket_DestroyQWebSocket(void* ptr)
{
	static_cast<QWebSocket*>(ptr)->~QWebSocket();
}

void QWebSocket_DestroyQWebSocketDefault(void* ptr)
{

}

void QWebSocket_TimerEvent(void* ptr, void* event)
{
	static_cast<QWebSocket*>(ptr)->timerEvent(static_cast<QTimerEvent*>(event));
}

void QWebSocket_TimerEventDefault(void* ptr, void* event)
{
	static_cast<QWebSocket*>(ptr)->QWebSocket::timerEvent(static_cast<QTimerEvent*>(event));
}

void QWebSocket_ChildEvent(void* ptr, void* event)
{
	static_cast<QWebSocket*>(ptr)->childEvent(static_cast<QChildEvent*>(event));
}

void QWebSocket_ChildEventDefault(void* ptr, void* event)
{
	static_cast<QWebSocket*>(ptr)->QWebSocket::childEvent(static_cast<QChildEvent*>(event));
}

void QWebSocket_ConnectNotify(void* ptr, void* sign)
{
	static_cast<QWebSocket*>(ptr)->connectNotify(*static_cast<QMetaMethod*>(sign));
}

void QWebSocket_ConnectNotifyDefault(void* ptr, void* sign)
{
	static_cast<QWebSocket*>(ptr)->QWebSocket::connectNotify(*static_cast<QMetaMethod*>(sign));
}

void QWebSocket_CustomEvent(void* ptr, void* event)
{
	static_cast<QWebSocket*>(ptr)->customEvent(static_cast<QEvent*>(event));
}

void QWebSocket_CustomEventDefault(void* ptr, void* event)
{
	static_cast<QWebSocket*>(ptr)->QWebSocket::customEvent(static_cast<QEvent*>(event));
}

void QWebSocket_DeleteLater(void* ptr)
{
	QMetaObject::invokeMethod(static_cast<QWebSocket*>(ptr), "deleteLater");
}

void QWebSocket_DeleteLaterDefault(void* ptr)
{
	static_cast<QWebSocket*>(ptr)->QWebSocket::deleteLater();
}

void QWebSocket_DisconnectNotify(void* ptr, void* sign)
{
	static_cast<QWebSocket*>(ptr)->disconnectNotify(*static_cast<QMetaMethod*>(sign));
}

void QWebSocket_DisconnectNotifyDefault(void* ptr, void* sign)
{
	static_cast<QWebSocket*>(ptr)->QWebSocket::disconnectNotify(*static_cast<QMetaMethod*>(sign));
}

char QWebSocket_Event(void* ptr, void* e)
{
	return static_cast<QWebSocket*>(ptr)->event(static_cast<QEvent*>(e));
}

char QWebSocket_EventDefault(void* ptr, void* e)
{
	return static_cast<QWebSocket*>(ptr)->QWebSocket::event(static_cast<QEvent*>(e));
}

char QWebSocket_EventFilter(void* ptr, void* watched, void* event)
{
	return static_cast<QWebSocket*>(ptr)->eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
}

char QWebSocket_EventFilterDefault(void* ptr, void* watched, void* event)
{
	return static_cast<QWebSocket*>(ptr)->QWebSocket::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
}

void* QWebSocket_MetaObject(void* ptr)
{
	return const_cast<QMetaObject*>(static_cast<QWebSocket*>(ptr)->metaObject());
}

void* QWebSocket_MetaObjectDefault(void* ptr)
{
	return const_cast<QMetaObject*>(static_cast<QWebSocket*>(ptr)->QWebSocket::metaObject());
}

void* QWebSocketCorsAuthenticator_NewQWebSocketCorsAuthenticator3(void* other)
{
	return new QWebSocketCorsAuthenticator(*static_cast<QWebSocketCorsAuthenticator*>(other));
}

void* QWebSocketCorsAuthenticator_NewQWebSocketCorsAuthenticator(char* origin)
{
	return new QWebSocketCorsAuthenticator(QString(origin));
}

void* QWebSocketCorsAuthenticator_NewQWebSocketCorsAuthenticator2(void* other)
{
	return new QWebSocketCorsAuthenticator(*static_cast<QWebSocketCorsAuthenticator*>(other));
}

char QWebSocketCorsAuthenticator_Allowed(void* ptr)
{
	return static_cast<QWebSocketCorsAuthenticator*>(ptr)->allowed();
}

char* QWebSocketCorsAuthenticator_Origin(void* ptr)
{
	return const_cast<char*>(static_cast<QWebSocketCorsAuthenticator*>(ptr)->origin().toUtf8().prepend("WHITESPACE").constData()+10);
}

void QWebSocketCorsAuthenticator_SetAllowed(void* ptr, char allowed)
{
	static_cast<QWebSocketCorsAuthenticator*>(ptr)->setAllowed(allowed != 0);
}

void QWebSocketCorsAuthenticator_Swap(void* ptr, void* other)
{
	static_cast<QWebSocketCorsAuthenticator*>(ptr)->swap(*static_cast<QWebSocketCorsAuthenticator*>(other));
}

void QWebSocketCorsAuthenticator_DestroyQWebSocketCorsAuthenticator(void* ptr)
{
	static_cast<QWebSocketCorsAuthenticator*>(ptr)->~QWebSocketCorsAuthenticator();
}

class MyQWebSocketServer: public QWebSocketServer
{
public:
	MyQWebSocketServer(const QString &serverName, SslMode secureMode, QObject *parent) : QWebSocketServer(serverName, secureMode, parent) {};
	void Signal_AcceptError(QAbstractSocket::SocketError socketError) { callbackQWebSocketServer_AcceptError(this, socketError); };
	void Signal_Closed() { callbackQWebSocketServer_Closed(this); };
	void Signal_NewConnection() { callbackQWebSocketServer_NewConnection(this); };
	QWebSocket * nextPendingConnection() { return static_cast<QWebSocket*>(callbackQWebSocketServer_NextPendingConnection(this)); };
	void Signal_OriginAuthenticationRequired(QWebSocketCorsAuthenticator * authenticator) { callbackQWebSocketServer_OriginAuthenticationRequired(this, authenticator); };
	void Signal_PeerVerifyError(const QSslError & error) { callbackQWebSocketServer_PeerVerifyError(this, const_cast<QSslError*>(&error)); };
	 ~MyQWebSocketServer() { callbackQWebSocketServer_DestroyQWebSocketServer(this); };
	void timerEvent(QTimerEvent * event) { callbackQWebSocketServer_TimerEvent(this, event); };
	void childEvent(QChildEvent * event) { callbackQWebSocketServer_ChildEvent(this, event); };
	void connectNotify(const QMetaMethod & sign) { callbackQWebSocketServer_ConnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	void customEvent(QEvent * event) { callbackQWebSocketServer_CustomEvent(this, event); };
	void deleteLater() { callbackQWebSocketServer_DeleteLater(this); };
	void disconnectNotify(const QMetaMethod & sign) { callbackQWebSocketServer_DisconnectNotify(this, const_cast<QMetaMethod*>(&sign)); };
	bool event(QEvent * e) { return callbackQWebSocketServer_Event(this, e) != 0; };
	bool eventFilter(QObject * watched, QEvent * event) { return callbackQWebSocketServer_EventFilter(this, watched, event) != 0; };
	const QMetaObject * metaObject() const { return static_cast<QMetaObject*>(callbackQWebSocketServer_MetaObject(const_cast<MyQWebSocketServer*>(this))); };
};

void* QWebSocketServer_NewQWebSocketServer(char* serverName, long long secureMode, void* parent)
{
	return new MyQWebSocketServer(QString(serverName), static_cast<QWebSocketServer::SslMode>(secureMode), static_cast<QObject*>(parent));
}

void QWebSocketServer_ConnectAcceptError(void* ptr)
{
	QObject::connect(static_cast<QWebSocketServer*>(ptr), static_cast<void (QWebSocketServer::*)(QAbstractSocket::SocketError)>(&QWebSocketServer::acceptError), static_cast<MyQWebSocketServer*>(ptr), static_cast<void (MyQWebSocketServer::*)(QAbstractSocket::SocketError)>(&MyQWebSocketServer::Signal_AcceptError));
}

void QWebSocketServer_DisconnectAcceptError(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocketServer*>(ptr), static_cast<void (QWebSocketServer::*)(QAbstractSocket::SocketError)>(&QWebSocketServer::acceptError), static_cast<MyQWebSocketServer*>(ptr), static_cast<void (MyQWebSocketServer::*)(QAbstractSocket::SocketError)>(&MyQWebSocketServer::Signal_AcceptError));
}

void QWebSocketServer_AcceptError(void* ptr, long long socketError)
{
	static_cast<QWebSocketServer*>(ptr)->acceptError(static_cast<QAbstractSocket::SocketError>(socketError));
}

void QWebSocketServer_Close(void* ptr)
{
	static_cast<QWebSocketServer*>(ptr)->close();
}

void QWebSocketServer_ConnectClosed(void* ptr)
{
	QObject::connect(static_cast<QWebSocketServer*>(ptr), static_cast<void (QWebSocketServer::*)()>(&QWebSocketServer::closed), static_cast<MyQWebSocketServer*>(ptr), static_cast<void (MyQWebSocketServer::*)()>(&MyQWebSocketServer::Signal_Closed));
}

void QWebSocketServer_DisconnectClosed(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocketServer*>(ptr), static_cast<void (QWebSocketServer::*)()>(&QWebSocketServer::closed), static_cast<MyQWebSocketServer*>(ptr), static_cast<void (MyQWebSocketServer::*)()>(&MyQWebSocketServer::Signal_Closed));
}

void QWebSocketServer_Closed(void* ptr)
{
	static_cast<QWebSocketServer*>(ptr)->closed();
}

char* QWebSocketServer_ErrorString(void* ptr)
{
	return const_cast<char*>(static_cast<QWebSocketServer*>(ptr)->errorString().toUtf8().prepend("WHITESPACE").constData()+10);
}

char QWebSocketServer_HasPendingConnections(void* ptr)
{
	return static_cast<QWebSocketServer*>(ptr)->hasPendingConnections();
}

char QWebSocketServer_IsListening(void* ptr)
{
	return static_cast<QWebSocketServer*>(ptr)->isListening();
}

char QWebSocketServer_Listen(void* ptr, void* address, unsigned short port)
{
	return static_cast<QWebSocketServer*>(ptr)->listen(*static_cast<QHostAddress*>(address), port);
}

int QWebSocketServer_MaxPendingConnections(void* ptr)
{
	return static_cast<QWebSocketServer*>(ptr)->maxPendingConnections();
}

void QWebSocketServer_ConnectNewConnection(void* ptr)
{
	QObject::connect(static_cast<QWebSocketServer*>(ptr), static_cast<void (QWebSocketServer::*)()>(&QWebSocketServer::newConnection), static_cast<MyQWebSocketServer*>(ptr), static_cast<void (MyQWebSocketServer::*)()>(&MyQWebSocketServer::Signal_NewConnection));
}

void QWebSocketServer_DisconnectNewConnection(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocketServer*>(ptr), static_cast<void (QWebSocketServer::*)()>(&QWebSocketServer::newConnection), static_cast<MyQWebSocketServer*>(ptr), static_cast<void (MyQWebSocketServer::*)()>(&MyQWebSocketServer::Signal_NewConnection));
}

void QWebSocketServer_NewConnection(void* ptr)
{
	static_cast<QWebSocketServer*>(ptr)->newConnection();
}

void* QWebSocketServer_NextPendingConnection(void* ptr)
{
	return static_cast<QWebSocketServer*>(ptr)->nextPendingConnection();
}

void* QWebSocketServer_NextPendingConnectionDefault(void* ptr)
{
	return static_cast<QWebSocketServer*>(ptr)->QWebSocketServer::nextPendingConnection();
}

void QWebSocketServer_ConnectOriginAuthenticationRequired(void* ptr)
{
	QObject::connect(static_cast<QWebSocketServer*>(ptr), static_cast<void (QWebSocketServer::*)(QWebSocketCorsAuthenticator *)>(&QWebSocketServer::originAuthenticationRequired), static_cast<MyQWebSocketServer*>(ptr), static_cast<void (MyQWebSocketServer::*)(QWebSocketCorsAuthenticator *)>(&MyQWebSocketServer::Signal_OriginAuthenticationRequired));
}

void QWebSocketServer_DisconnectOriginAuthenticationRequired(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocketServer*>(ptr), static_cast<void (QWebSocketServer::*)(QWebSocketCorsAuthenticator *)>(&QWebSocketServer::originAuthenticationRequired), static_cast<MyQWebSocketServer*>(ptr), static_cast<void (MyQWebSocketServer::*)(QWebSocketCorsAuthenticator *)>(&MyQWebSocketServer::Signal_OriginAuthenticationRequired));
}

void QWebSocketServer_OriginAuthenticationRequired(void* ptr, void* authenticator)
{
	static_cast<QWebSocketServer*>(ptr)->originAuthenticationRequired(static_cast<QWebSocketCorsAuthenticator*>(authenticator));
}

void QWebSocketServer_PauseAccepting(void* ptr)
{
	static_cast<QWebSocketServer*>(ptr)->pauseAccepting();
}

void QWebSocketServer_ConnectPeerVerifyError(void* ptr)
{
	QObject::connect(static_cast<QWebSocketServer*>(ptr), static_cast<void (QWebSocketServer::*)(const QSslError &)>(&QWebSocketServer::peerVerifyError), static_cast<MyQWebSocketServer*>(ptr), static_cast<void (MyQWebSocketServer::*)(const QSslError &)>(&MyQWebSocketServer::Signal_PeerVerifyError));
}

void QWebSocketServer_DisconnectPeerVerifyError(void* ptr)
{
	QObject::disconnect(static_cast<QWebSocketServer*>(ptr), static_cast<void (QWebSocketServer::*)(const QSslError &)>(&QWebSocketServer::peerVerifyError), static_cast<MyQWebSocketServer*>(ptr), static_cast<void (MyQWebSocketServer::*)(const QSslError &)>(&MyQWebSocketServer::Signal_PeerVerifyError));
}

void QWebSocketServer_PeerVerifyError(void* ptr, void* error)
{
	static_cast<QWebSocketServer*>(ptr)->peerVerifyError(*static_cast<QSslError*>(error));
}

void* QWebSocketServer_Proxy(void* ptr)
{
	return new QNetworkProxy(static_cast<QWebSocketServer*>(ptr)->proxy());
}

void QWebSocketServer_ResumeAccepting(void* ptr)
{
	static_cast<QWebSocketServer*>(ptr)->resumeAccepting();
}

long long QWebSocketServer_SecureMode(void* ptr)
{
	return static_cast<QWebSocketServer*>(ptr)->secureMode();
}

void* QWebSocketServer_ServerAddress(void* ptr)
{
	return new QHostAddress(static_cast<QWebSocketServer*>(ptr)->serverAddress());
}

char* QWebSocketServer_ServerName(void* ptr)
{
	return const_cast<char*>(static_cast<QWebSocketServer*>(ptr)->serverName().toUtf8().prepend("WHITESPACE").constData()+10);
}

unsigned short QWebSocketServer_ServerPort(void* ptr)
{
	return static_cast<QWebSocketServer*>(ptr)->serverPort();
}

void* QWebSocketServer_ServerUrl(void* ptr)
{
	return new QUrl(static_cast<QWebSocketServer*>(ptr)->serverUrl());
}

void QWebSocketServer_SetMaxPendingConnections(void* ptr, int numConnections)
{
	static_cast<QWebSocketServer*>(ptr)->setMaxPendingConnections(numConnections);
}

void QWebSocketServer_SetProxy(void* ptr, void* networkProxy)
{
	static_cast<QWebSocketServer*>(ptr)->setProxy(*static_cast<QNetworkProxy*>(networkProxy));
}

void QWebSocketServer_SetServerName(void* ptr, char* serverName)
{
	static_cast<QWebSocketServer*>(ptr)->setServerName(QString(serverName));
}

char QWebSocketServer_SetSocketDescriptor(void* ptr, int socketDescriptor)
{
	return static_cast<QWebSocketServer*>(ptr)->setSocketDescriptor(socketDescriptor);
}

void QWebSocketServer_SetSslConfiguration(void* ptr, void* sslConfiguration)
{
	static_cast<QWebSocketServer*>(ptr)->setSslConfiguration(*static_cast<QSslConfiguration*>(sslConfiguration));
}

int QWebSocketServer_SocketDescriptor(void* ptr)
{
	return static_cast<QWebSocketServer*>(ptr)->socketDescriptor();
}

void* QWebSocketServer_SslConfiguration(void* ptr)
{
	return new QSslConfiguration(static_cast<QWebSocketServer*>(ptr)->sslConfiguration());
}

void QWebSocketServer_DestroyQWebSocketServer(void* ptr)
{
	static_cast<QWebSocketServer*>(ptr)->~QWebSocketServer();
}

void QWebSocketServer_DestroyQWebSocketServerDefault(void* ptr)
{

}

void QWebSocketServer_TimerEvent(void* ptr, void* event)
{
	static_cast<QWebSocketServer*>(ptr)->timerEvent(static_cast<QTimerEvent*>(event));
}

void QWebSocketServer_TimerEventDefault(void* ptr, void* event)
{
	static_cast<QWebSocketServer*>(ptr)->QWebSocketServer::timerEvent(static_cast<QTimerEvent*>(event));
}

void QWebSocketServer_ChildEvent(void* ptr, void* event)
{
	static_cast<QWebSocketServer*>(ptr)->childEvent(static_cast<QChildEvent*>(event));
}

void QWebSocketServer_ChildEventDefault(void* ptr, void* event)
{
	static_cast<QWebSocketServer*>(ptr)->QWebSocketServer::childEvent(static_cast<QChildEvent*>(event));
}

void QWebSocketServer_ConnectNotify(void* ptr, void* sign)
{
	static_cast<QWebSocketServer*>(ptr)->connectNotify(*static_cast<QMetaMethod*>(sign));
}

void QWebSocketServer_ConnectNotifyDefault(void* ptr, void* sign)
{
	static_cast<QWebSocketServer*>(ptr)->QWebSocketServer::connectNotify(*static_cast<QMetaMethod*>(sign));
}

void QWebSocketServer_CustomEvent(void* ptr, void* event)
{
	static_cast<QWebSocketServer*>(ptr)->customEvent(static_cast<QEvent*>(event));
}

void QWebSocketServer_CustomEventDefault(void* ptr, void* event)
{
	static_cast<QWebSocketServer*>(ptr)->QWebSocketServer::customEvent(static_cast<QEvent*>(event));
}

void QWebSocketServer_DeleteLater(void* ptr)
{
	QMetaObject::invokeMethod(static_cast<QWebSocketServer*>(ptr), "deleteLater");
}

void QWebSocketServer_DeleteLaterDefault(void* ptr)
{
	static_cast<QWebSocketServer*>(ptr)->QWebSocketServer::deleteLater();
}

void QWebSocketServer_DisconnectNotify(void* ptr, void* sign)
{
	static_cast<QWebSocketServer*>(ptr)->disconnectNotify(*static_cast<QMetaMethod*>(sign));
}

void QWebSocketServer_DisconnectNotifyDefault(void* ptr, void* sign)
{
	static_cast<QWebSocketServer*>(ptr)->QWebSocketServer::disconnectNotify(*static_cast<QMetaMethod*>(sign));
}

char QWebSocketServer_Event(void* ptr, void* e)
{
	return static_cast<QWebSocketServer*>(ptr)->event(static_cast<QEvent*>(e));
}

char QWebSocketServer_EventDefault(void* ptr, void* e)
{
	return static_cast<QWebSocketServer*>(ptr)->QWebSocketServer::event(static_cast<QEvent*>(e));
}

char QWebSocketServer_EventFilter(void* ptr, void* watched, void* event)
{
	return static_cast<QWebSocketServer*>(ptr)->eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
}

char QWebSocketServer_EventFilterDefault(void* ptr, void* watched, void* event)
{
	return static_cast<QWebSocketServer*>(ptr)->QWebSocketServer::eventFilter(static_cast<QObject*>(watched), static_cast<QEvent*>(event));
}

void* QWebSocketServer_MetaObject(void* ptr)
{
	return const_cast<QMetaObject*>(static_cast<QWebSocketServer*>(ptr)->metaObject());
}

void* QWebSocketServer_MetaObjectDefault(void* ptr)
{
	return const_cast<QMetaObject*>(static_cast<QWebSocketServer*>(ptr)->QWebSocketServer::metaObject());
}

