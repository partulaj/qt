/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the utility applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef PMMAPPERAPP_H
#define PMMAPPERAPP_H

//  INCLUDES
#include <eikapp.h>
#include <eikdoc.h>
#include <e32std.h>
#include <aknViewAppUi.h>

// CONSTANTS
const TUid KUidPMMapperApplication = { 0x2002121F };


// FORWARD DECLARATIONS
class CPixelMetricsMapperView;
class MAknsSkinInstance;

// CLASS DECLARATION
/**
*  CPixelMetricsMapperDocument
*/
class CPixelMetricsMapperDocument : public CEikDocument
    {
    public:  // Constructors and destructor

        /**
        * Symbian 2nd phase constructor.
        */
        void ConstructL();

        /**
        * Constructor.
        */
        CPixelMetricsMapperDocument( CEikApplication& aApp )
            : CEikDocument( aApp ) {}

        /**
        * Destructor.
        */
        ~CPixelMetricsMapperDocument(){}

    public: // Functions from base classes

        /**
        * From CEikDocument.
        */
        CFileStore* OpenFileL(
            TBool         /*aDoOpen*/,
            const TDesC&  /*aFilename*/,
            RFs&          /*aFs*/ )
            {
            return NULL;
            }

    private: // Functions from base classes

        /**
        * From CEikDocument.
        */
        CEikAppUi* CreateAppUiL();
    };

/**
*  CPixelMetricsMapperAppUi
*/
class CPixelMetricsMapperAppUi : public CAknViewAppUi
    {
    public:  // Constructors and destructor

        /**
        * Constructor.
        */
        CPixelMetricsMapperAppUi();

        /**
        * Symbian 2nd phase constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CPixelMetricsMapperAppUi();

    private: // Functions from base classes

        /**
        * From CEikAppUi.
        */
        void HandleCommandL(TInt aCommand);

        /**
        * From CEikAppUi.
        */
        virtual TKeyResponse HandleKeyEventL(
            const TKeyEvent& aKeyEvent,
            TEventCode aType );

    private:

        /**
        * Shows text given.
        */
        void ShowL( const TDesC& aText, TBool& aLast, const TBool& aFileOutput = EFalse );
        void ShowSingleValueL(TInt& aPixelMetric, TInt& aValue, TBool& aLast);
        void ClearL();
        void CreateHeaderFileL() const;

        TFileName CreateLayoutNameL(TFileText& aFileHandle) const;

    private:    // Data

        // Test view.
        CPixelMetricsMapperView* iView;

        CEikDialog* iDialog;

        TBool iFileOutputOn;
        TBool iMode;

        CFbsBitmap* icon;
        CFbsBitmap* iconMask;

    };


/**
*  CPixelMetricsMapperApplication
*/
class CPixelMetricsMapperApplication : public CEikApplication
    {
    private: // Functions from base classes

        /**
        * From CApaApplication.
        */
        CApaDocument* CreateDocumentL();

        /**
        * From CApaApplication.
        */
        TUid AppDllUid() const;
    };


#endif  // PMMAPPERAPP_H


// End of File
