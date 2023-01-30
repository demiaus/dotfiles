window.addEventListener("keyup",(keyevent) => {
 if(keyevent.ctrlKey && keyevent.key === "Escape") {
  document.activeElement.blur();
 }
});
