// ********************************************************************************************************************
// Tianchi C++ library for Qt (open source)
// ��ع���Դ���
// ��Ȩ���� (C) ��ع���Դ��⿪����
// ��ȨЭ�飺���Ķ���ع���Դ��⸽������ȨЭ��
// ********************************************************************************************************************
// �ĵ�˵�������ù��ܺ���
// ====================================================================================================================
// ������־��
// ����         ��Ա        ˵��
// --------------------------------------------------------------------------------------------------------------------
// 2013.04.10   ʥ������    ����
//
// ====================================================================================================================
/// @file Utils.h ���ù��ܺ���
// ====================================================================================================================
#ifndef TIANCHI_UTILS_H
#define TIANCHI_UTILS_H

#include "Global.h"

#ifdef QT_WIDGETS_LIB
    #include <QMessageBox>
#endif

#include <QTextCodec>
#include <QVariant>

#include <QDateTime>

#include <QString>
#include <QStringList>
#include <QByteArray>
#include <QComboBox>

#include <QThread>


TIANCHI_BEGIN_NAMESPACE

/// @brief ����ģʽ�ı�ʶ����
namespace OperMode
{
const int Append = 1; ///< ���ӻ��½�
const int Change = 2; ///< �޸�
const int Delete = 4; ///< ɾ��
};

/// @brief ����С�����ۺϺ�����
class TIANCHI_API Utils
{
public:
    /// @brief �� key=value �ṹ���ı�ת��Ϊ map �ṹ
    static QHash<QString, QString> StringToMap(const QString& mapStrings);
    /// @brief �� key=value �ṹ���ı�ת��Ϊ map �ṹ
    static QHash<QString, QString> StringToMap(const QStringList& mapStrings);

    /// @brief ����ת�ַ�����
    static char typeFrom(QVariant::Type type);
    /// @brief ����ת�ַ�����
    static char typeFrom(const QVariant& v)
    {
        return typeFrom(v.type());
    }

    /// @brief ���ص�ǰʱ���ַ�����yyyy-MM-dd HH:mm:ss.zzz
    static QString YYYY_MM_DD_HH_MM_SS_ZZZ();
    /// @brief ���ص�ǰʱ���ַ�����yyyy-MM-dd HH:mm:ss
    static QString YYYY_MM_DD_HH_MM_SS();
    /// @brief ת���ַ���Ϊ����ʱ��
    static QDateTime toDateTime(const QString& text);

    /// @brief ����18λ��λ֤�����һλУ����
    static char getIDCardVerifyCode(const QByteArray& id);

    /// @brief ȡ�������ں�ʱ�䣬���ô��Ĵ���������±���
    static QDateTime complieDateTime(const QString& complieDate, const QString& time);

    /// @brief ��Ŀ¼����Ŀ¼�м����������ļ���
    static QStringList searchFiles(const QString& path);
};

TIANCHI_END_NAMESPACE


#endif // TIANCHI_UTILS_H