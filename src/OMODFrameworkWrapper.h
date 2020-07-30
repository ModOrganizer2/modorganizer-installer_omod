#pragma once

#include <QCoreApplication>
#include <QProgressDialog>
#include <QStack>

#include <iplugininstaller.h>

#include "implementations/CodeProgress.h"
#include "QObject_unique_ptr.h"

// define this here as it's going to be used a lot by things using this class' message box wrappers.
template<class T>
T& unused_out(T&& t) { return t; }

class OMODFrameworkWrapper : public QObject
{
  Q_OBJECT

public:
  using EInstallResult = MOBase::IPluginInstaller::EInstallResult;

  OMODFrameworkWrapper(MOBase::IOrganizer* organizer, QWidget* parentWidget);

  EInstallResult installInAnotherThread(MOBase::GuessedValue<QString>& modName, QString gameName, const QString& archiveName, const QString& version, int nexusID);

  EInstallResult install(MOBase::GuessedValue<QString>& modName, QString gameName, const QString& archiveName, const QString& version, int nexusID);

protected:
  void initFrameworkSettings();

  void pushTempPath(const QString& tempPath);

  void popTempPath();

signals:
  void createMod(MOBase::IModInterface*& modInterfaceOut, MOBase::GuessedValue<QString>& modName);

  void displayReadme(const QString& modName, const QString& readme);

  void showWaitDialog(QString message);
  void hideWaitDialog();

protected slots:
  void createModSlot(MOBase::IModInterface*& modInterfaceOut, MOBase::GuessedValue<QString>& modName);
  void displayReadmeSlot(const QString& modName, const QString& readme);
  
  void showWaitDialogSlot(QString message);
  void hideWaitDialogSlot();

private:
  __declspec(noinline) void constructorHelper();

  MOBase::IOrganizer* mMoInfo;
  QWidget* mParentWidget;

  QStack<QString> mTempPathStack;

  QObject_unique_ptr<QProgressDialog> mWaitDialog;
};
