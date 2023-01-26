var textFields = document.getElementsByClassName('form-control');
var storageKeys = ["RockyNotesText1", "RockyNotesText2", "RockyNotesText3"];

for (var i = 0; i < textFields.length; i++)
{
	textFields[i].value = localStorage.getItem(storageKeys[i]);
}

for (var i = 0; i < textFields.length; i++) {
	textFields[i].addEventListener('input', function (e) {
		
		var eventId = e.target.id;
		var text = e.target.value;
		if (eventId === "notesText1") {
			localStorage.setItem(storageKeys[0], text);
		}
		else if (eventId === "notesText2") {
			localStorage.setItem(storageKeys[1], text);
		}
		else if (eventId === "notesText3") {
			localStorage.setItem(storageKeys[2], text);
		}
	}, false);
}
