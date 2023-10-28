#include "texteditor.h"
#include "ui_texteditor.h"

TextEditor::TextEditor(const QString &fil, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    QSettings settings;
    auto font = settings.value("viewFont").value<QFont>();
    ui->textEdit->setCurrentFont(font);

    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentModified()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->actionCut, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    connect(ui->actionCopy, SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    connect(ui->actionPaste, SIGNAL(triggered()), ui->textEdit, SLOT(paste()));
    connect(ui->actionUndo, SIGNAL(triggered()), ui->textEdit, SLOT(undo()));
    connect(ui->actionRedo, SIGNAL(triggered()), ui->textEdit, SLOT(redo()));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveFileAs()));

    ui->actionCopy->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);

    setAttribute(Qt::WA_DeleteOnClose);

    loadFile(fil);
}

TextEditor::~TextEditor()
{
    delete ui;
}


void TextEditor::on_actionNew_triggered()
{
    auto newWindow = new TextEditor();
    newWindow->show();
}

void TextEditor::documentModified(){
    setWindowModified(true);
}

void TextEditor::closeEvent(QCloseEvent *eve){
    if(isWindowModified())
    {
        switch(QMessageBox::warning(this, "Документ изменен",
                                     "Документ был изменен. "
                                     "Хотите сохранить изменения?\n"
                                     "Вы можете потерять данные.",
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                     QMessageBox::Cancel))
        {
        case QMessageBox::Yes:
            saveFile();
            break;
        case QMessageBox::No:
            eve->accept();
            break;
        case QMessageBox::Cancel:
            eve->ignore();
            break;
        default:
            break;
        }
    }
    else
    {
        eve->accept();
    }

}

void TextEditor::on_actionSelectFont_triggered()
{
    auto font = ui->textEdit->font();
    bool status;
    auto newFont = QFontDialog::getFont(&status, font);
    if (status == true){
        ui->textEdit->setCurrentFont(newFont);
        QSettings settings;
        settings.setValue("viewFont", newFont);
    }
}



void TextEditor::loadFile(const QString &fil){
    if (fil.isEmpty()){
        setFileName(QString());
        return;
    }
    QFile file(fil);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Предупреждение", "Невозможно открыть этот файл");
        setFileName(QString());
        return;
    }

    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());

    file.close();
    setFileName(fil);
    setWindowModified(false);
}

void TextEditor::setFileName(const QString &fil){
    m_fileName = fil;
    setWindowTitle(QString("%1[*] - %2")
                       .arg(m_fileName.isNull()?"Безымянный":QFileInfo(m_fileName).fileName())
                       .arg(QApplication::applicationName())
    );

}

void TextEditor::on_actionOpen_triggered()
{
    QString fil = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::currentPath(), "Текстовые файлы(*.txt)");
    if (fil.isNull()){
        return;
    }

    if (m_fileName.isNull() && !isWindowModified()){
        loadFile(fil);
    } else {
        auto newWindow = new TextEditor(fil);
        newWindow->show();
    }
}

bool TextEditor::saveFileAs(){
    QString fil = QFileDialog::getSaveFileName(this, "Сохранить документ",
                                                    m_fileName.isNull()?QDir::currentPath():m_fileName, "Текстовые файлы(*.txt)");
    if (fil.isNull()){
        return false;
    }
    setFileName(fil);
    return saveFile();
}

bool TextEditor::saveFile(){
    if (m_fileName.isNull()){
        return saveFileAs();
    }

    QFile file(m_fileName);

    if (!file.open(QIODevice::WriteOnly  | QIODevice::Text)){
        QMessageBox::warning(this, "Предупреждение", "Невозможно");
        setFileName(QString());
        return false;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();
    setWindowModified(false);
    return true;
}

void TextEditor::on_actionAbout_triggered()
{
    QMessageBox::about(this, "О программе", "эта программа никем не уважаема");
}
