// ********************************************************************************************************************
// Tianchi C++ library for Qt (open source)
// ��ع���Դ���
// ��Ȩ���� (C) ��ع���Դ��⿪����
// ��ȨЭ�飺���Ķ���ع���Դ��⸽������ȨЭ��
// ********************************************************************************************************************
// �ĵ�˵����һЩ���õ�С��
// ====================================================================================================================
// ������־��
// ����         ��Ա        ˵��
// --------------------------------------------------------------------------------------------------------------------
// 2013.04.10   ʥ������    ����
//
// ====================================================================================================================
/// @file Classes.h һЩ���õ�С��
#ifndef TIANCHI_CLASSES_H
#define TIANCHI_CLASSES_H

#include "Global.h"

#include <QDateTime>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QElapsedTimer>
#include <QHash>

TIANCHI_BEGIN_NAMESPACE

QT_USE_NAMESPACE

/// @brief �����Ϣ�࣬������ C/S �еĿͻ����û���Ϣ����
class TIANCHI_API Player : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int       userNo    READ userNo    WRITE setUserNo   ) ///< �û����
    Q_PROPERTY(QString   userID    READ userID    WRITE setUserID   ) ///< �û�ID
    Q_PROPERTY(QString   username  READ username  WRITE setUsername ) ///< �û�ȫ��
    Q_PROPERTY(bool      loggedIn  READ loggedIn  WRITE setLoggedIn ) ///< �Ƿ��ѵ�¼
    Q_PROPERTY(QDateTime loginTime READ loginTime WRITE setLoginTime) ///< ��¼ʱ��

public:
    /// �û�Ȩ��
    typedef enum AuthLevel
    {
        AUTH_SYSADMIN = 999,  ///< ���ϵͳ������ԱȨ��
        AUTH_ADMIN    = 888,  ///< ����û�������ԱȨ��
        AUTH_MANAGER  =  99,  ///< �û���������Ȩ��
        AUTH_USER     =   9,  ///< �û�������ͨ�û�Ȩ��
        AUTH_GUEST    =   1,  ///< �û������ÿͼ�Ȩ��
    };


    Player();
    Player &operator=(const Player&);

    inline int          userNo() const { return m_userNo; }
    /// @brief ָ���û��� No
    inline void         setUserNo(int value) { m_userNo = value; }
    inline QString      userID() const { return m_userID; }
    /// @brief ָ���û��� ID
    inline void         setUserID(const QString& value) { m_userID = value.trimmed(); }
    inline QString      username() const { return m_username; }
    /// @brief ָ���û��� username
    inline void         setUsername(const QString& value) { m_username = value.trimmed(); }
    inline int          userLevel() const { return m_userLevel; }
    /// @brief ָ���û���Ȩ�޼���
    inline void         setUserLevel(int value) { m_userLevel = value; }

    int                 authority(const QString& key) const;
    /// @brief ָ���û���Ȩ��ģ�鼶��
    inline void         setAuthority(const QString& key, int auth) { m_authority[key] = auth; }
    /// @brief ���������û���ȫ��Ȩ�޼���
    void                setAuthorityText(const QString& value);
    /// @brief ���������û���ȫ��Ȩ�޼���
    void                setAuthorityText(const QStringList& value);

    inline QString      loginID() const { return m_loginID; }
    /// @brief �����û��ĵ�¼����
    inline void         setLoginID(const QString& value) { m_loginID = value.trimmed(); }
    inline QString      password() const { return m_password; }
    /// @brief �����û��ĵ�¼����
    inline void         setPassword(const QString& value) { m_password = value.trimmed(); }
    /// @brief ����Ƿ��ѵ�¼
    inline bool         loggedIn() const { return m_loggedIn; }
    /// @brief ָ������Ƿ��ѵ�¼
           void         setLoggedIn(bool value);
    /// @brief �������Ϊ�ѵ�¼
    inline void         setLoggedIn() { setLoggedIn(true); }
    /// @brief ��ҵĵ�¼ʱ��
    inline QDateTime    loginTime() const { return m_loginTime; }
    /// @brief ָ����ҵĵ�¼ʱ��
    inline void         setLoginTime(QDateTime value) { m_loginTime = value; m_loggedIn = true; }

    /// @brief ������Ҿ��δ��¼������
    /// ������������ߺ���ʾ���ѻ���ʱ��
    inline int          noLoginTime() { return m_loggedIn ? 0 : m_noLoginTimer.elapsed()/1000; }

    /// @brief �����ҵ�������Ϣ
    void clear();

private:
    int                 m_userNo;
    QString             m_userID;
    QString             m_username;
    int                 m_userLevel;
    QHash<QString, int> m_authority;

    QString             m_loginID;
    QString             m_password;

    bool                m_loggedIn;
    QDateTime           m_loginTime;
    QElapsedTimer       m_noLoginTimer;
};

/// @brief ӳ��ִ�ж�����
class TIANCHI_API CInvokeObject
{
public:
    CInvokeObject(QObject* o=NULL, QByteArray m="")
            { init(o, m); }
    CInvokeObject &operator=(const CInvokeObject& from)
    {
        if ( this != &from )
        {
            this->m_object = from.m_object;
            this->m_method = from.m_method;
        }
        return *this;
    }
    inline void init(QObject* o, QByteArray m)
            { m_object = o; m_method = m; }

    inline bool queued(QGenericArgument val0 = QGenericArgument(0),
                       QGenericArgument val1 = QGenericArgument(),
                       QGenericArgument val2 = QGenericArgument(),
                       QGenericArgument val3 = QGenericArgument(),
                       QGenericArgument val4 = QGenericArgument(),
                       QGenericArgument val5 = QGenericArgument(),
                       QGenericArgument val6 = QGenericArgument(),
                       QGenericArgument val7 = QGenericArgument(),
                       QGenericArgument val8 = QGenericArgument(),
                       QGenericArgument val9 = QGenericArgument())
    {
        try {
            return m_object != NULL ? m_object->metaObject()->invokeMethod(m_object, m_method,
                                                                           Qt::QueuedConnection,
                                                                           val0, val1, val2, val3, val4,
                                                                           val5, val6, val7, val8, val9)
                                    : false;
        }catch(...)
        {
            return false;
        }
    }
    bool invoke(QGenericArgument val0 = QGenericArgument(0),
                       QGenericArgument val1 = QGenericArgument(),
                       QGenericArgument val2 = QGenericArgument(),
                       QGenericArgument val3 = QGenericArgument(),
                       QGenericArgument val4 = QGenericArgument(),
                       QGenericArgument val5 = QGenericArgument(),
                       QGenericArgument val6 = QGenericArgument(),
                       QGenericArgument val7 = QGenericArgument(),
                       QGenericArgument val8 = QGenericArgument(),
                       QGenericArgument val9 = QGenericArgument());

    inline bool isValid() const { return m_object != NULL && ! m_method.isEmpty(); }
private:
    QObject*    m_object;
    QByteArray  m_method;
};

/// @brief key=value ���ݸ�ʽת����
/// @note C/S �ܹ��У�������Ϣ���� key=value ��ʽ���ݣ��������� k=v ��Ϣ�Ķ�ȡ
class TIANCHI_API DBFields
{
public:
    DBFields() {}
    inline DBFields(QHash<QString, QByteArray> fields)
                    { setFields(fields); }

    static void addField(QByteArray& fieldBytes, const QString& name, const QVariant& value);
    static QHash<QString, QByteArray> getFields(const QByteArray& fieldBytes);

    void    setFields(QHash<QString, QByteArray> fields)
    {
        m_fields.clear();
        m_keys.clear();

        m_fields = fields;
        m_keys = m_fields.keys();
    }
    inline QByteArray value(const QString& key) const
    {
        return m_fields.value(key.trimmed().toLower());
    }

private:
    QHash<QString, QByteArray>  m_fields;
    QStringList m_keys;
};


TIANCHI_END_NAMESPACE

#endif // TIANCHI_CLASSES_H