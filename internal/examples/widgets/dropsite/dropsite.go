//source: http://doc.qt.io/qt-5/qtwidgets-draganddrop-dropsite-example.html

package main

import (
	"fmt"
	"os"

	"github.com/therecipe/qt/core"
	"github.com/therecipe/qt/gui"
	"github.com/therecipe/qt/widgets"
)

//go:generate qtmoc
type DropSiteWindow struct {
	widgets.QWidget

	_ func(mimeData *core.QMimeData) `slot:"updateFormatsTable"`
}

func main() {
	widgets.NewQApplication(len(os.Args), os.Args)

	var window = NewDropSiteWindow(nil, 0)

	var abstractLabel = widgets.NewQLabel2("This example accepts drags from other applications and displays the MIME types provided by the drag object.", nil, 0)
	abstractLabel.SetWordWrap(true)
	abstractLabel.AdjustSize()

	var dropArea = initDropArea()
	dropArea.ConnectChanged(func(mimeData *core.QMimeData) { window.UpdateFormatsTable(mimeData) })

	var formatsTable = widgets.NewQTableWidget(nil)
	formatsTable.SetColumnCount(2)
	formatsTable.SetEditTriggers(widgets.QAbstractItemView__NoEditTriggers)
	formatsTable.SetHorizontalHeaderLabels([]string{"Format", "Content"})
	formatsTable.HorizontalHeader().SetStretchLastSection(true)

	window.ConnectUpdateFormatsTable(func(mimeData *core.QMimeData) {
		formatsTable.SetRowCount(0)

		if mimeData == nil {
			return
		}

		for _, format := range mimeData.Formats() {
			var formatItem = widgets.NewQTableWidgetItem2(format, 0)
			formatItem.SetFlags(core.Qt__ItemIsEnabled)
			formatItem.SetTextAlignment(int(core.Qt__AlignTop | core.Qt__AlignLeft))

			var text string

			switch format {
			case "text/plain":
				{
					text = mimeData.Text()
				}

			case "text/html":
				{
					text = mimeData.Html()
				}

			case "text/uri-list":
				{
					text = mimeData.Text()
				}

			default:
				{
					var data = []byte(mimeData.Data(format))
					text = fmt.Sprintf("len %v: %v", len(data), data)
				}
			}

			var row = formatsTable.RowCount()
			formatsTable.InsertRow(row)
			formatsTable.SetItem(row, 0, widgets.NewQTableWidgetItem2(format, 0))
			formatsTable.SetItem(row, 1, widgets.NewQTableWidgetItem2(text, 0))
		}

		formatsTable.ResizeColumnToContents(0)
	})

	var (
		clearButton = widgets.NewQPushButton2("Clear", nil)
		quitButton  = widgets.NewQPushButton2("Quit", nil)

		buttonBox = widgets.NewQDialogButtonBox(nil)
	)

	buttonBox.AddButton(clearButton, widgets.QDialogButtonBox__ActionRole)
	buttonBox.AddButton(quitButton, widgets.QDialogButtonBox__RejectRole)

	quitButton.ConnectPressed(func() { window.Close() })
	clearButton.ConnectPressed(func() {
		dropArea.Clear()
		formatsTable.ClearContents()
		formatsTable.SetRowCount(0)
	})

	var mainLayout = widgets.NewQVBoxLayout()
	mainLayout.AddWidget(abstractLabel, 0, 0)
	mainLayout.AddWidget(dropArea, 0, 0)
	mainLayout.AddWidget(formatsTable, 0, 0)
	mainLayout.AddWidget(buttonBox, 0, 0)

	window.SetLayout(mainLayout)

	window.SetWindowTitle("Drop Site")
	window.SetMinimumSize2(350, 500)

	window.Show()

	widgets.QApplication_Exec()
}

type DropArea struct {
	widgets.QLabel

	_ func(mimeData *core.QMimeData) `signal:"changed"`
}

func initDropArea() *DropArea {
	var dropArea = NewDropArea(nil, 0)

	dropArea.SetMinimumSize2(200, 200)
	dropArea.SetFrameStyle(int(widgets.QFrame__Sunken) | int(widgets.QFrame__StyledPanel))
	dropArea.SetAlignment(core.Qt__AlignCenter)
	dropArea.SetAcceptDrops(true)
	dropArea.SetAutoFillBackground(true)
	dropArea.Clear()

	dropArea.ConnectDragEnterEvent(func(e *gui.QDragEnterEvent) {
		dropArea.SetText("<drop content>")
		dropArea.SetBackgroundRole(gui.QPalette__Highlight)

		e.AcceptProposedAction()
		dropArea.Changed(e.MimeData())
	})

	dropArea.ConnectDragMoveEvent(func(e *gui.QDragMoveEvent) {
		e.AcceptProposedAction()
	})

	dropArea.ConnectDropEvent(func(e *gui.QDropEvent) {
		var mimeData = e.MimeData()

		switch {
		case mimeData.HasImage():
			{
				dropArea.SetPixmap(gui.QPixmap_FromImage(gui.NewQImageFromPointer(mimeData.ImageData()), 0))
			}

		case mimeData.HasHtml():
			{
				dropArea.SetText(mimeData.Html())
				dropArea.SetTextFormat(core.Qt__RichText)
			}

		case mimeData.HasText():
			{
				dropArea.SetText(mimeData.Text())
				dropArea.SetTextFormat(core.Qt__PlainText)
			}

		case mimeData.HasUrls():
			{
				dropArea.SetText(mimeData.Text())
				dropArea.SetTextFormat(core.Qt__PlainText)
			}

		default:
			{
				dropArea.SetText("can't display data")
			}
		}

		dropArea.SetBackgroundRole(gui.QPalette__Dark)
		e.AcceptProposedAction()
	})

	dropArea.ConnectDragLeaveEvent(func(e *gui.QDragLeaveEvent) {
		dropArea.Clear()
		e.Accept()
	})

	dropArea.ConnectClear(func() {
		dropArea.SetText("<drop content>")
		dropArea.SetBackgroundRole(gui.QPalette__Dark)

		dropArea.Changed(nil)
	})

	return dropArea
}
