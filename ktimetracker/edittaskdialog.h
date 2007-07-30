/*
 *     Copyright (C) 1999 by Espen Sand <espensa@online.no>
 *                   2007 the ktimetracker developers
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License along
 *   with this program; if not, write to the
 *      Free Software Foundation, Inc.
 *      51 Franklin Street, Fifth Floor
 *      Boston, MA  02110-1301  USA.
 *
 */

#ifndef KARM_EDIT_TASK_DIALOG_H
#define KARM_EDIT_TASK_DIALOG_H

#include <QVector>

#include <KDialog>

#include "desktoplist.h"

class QCheckBox;
class QLabel;
class QRadioButton;

class KComboBox;
class KLineEdit;

class KArmTimeWidget;

/**
 * Dialog to add a new task or edit an existing task.
 */
class EditTaskDialog : public KDialog
{
  Q_OBJECT

  public:
    EditTaskDialog( QWidget *parent, const QString &caption, bool editDlg, 
                    DesktopList* desktopList = 0 );
    void setTask( const QString &name, long time, long sessionTime );
    QString taskName() const;

    // return user choices
    void status( long *time, long *timeDiff, 
                 long *session, long *sessionDiff, 
                 DesktopList *desktopList) const;

  private Q_SLOTS:
    void slotAbsolutePressed();
    void slotRelativePressed();
    void slotAutoTrackingPressed( bool checked );

  private:
    KLineEdit* _name;
    KArmTimeWidget* _timeTW;
    KArmTimeWidget* _sessionTW;
    KArmTimeWidget* _diffTW;
    KComboBox* _operator;
    QVector<QCheckBox*> _deskBox; // we only need an array, but ISO forbids
                                 // passing an array as a function argument

    long origTime;
    long origSession;

    QRadioButton *_absoluteRB;
    QRadioButton *_relativeRB;

    int desktopCount;

    QLabel* _timeLA;
    QLabel* _sessionLA;
};

#endif // KARM_EDIT_TASK_DIALOG
