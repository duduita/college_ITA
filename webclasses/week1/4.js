// Creating my movement function
function myMove(){
    // Creating my variables
    // Element (my square)
    var elem = document.getElementById("square");
    // Initial Position
    var pos = 0;
    var id = setInterval(frame, 5);
    function frame() {
        if (pos == 350) {
            clearInterval(id);
        } else {
            // Updating square's position
            pos++;
            elem.style.top = pos + "px";
            elem.style.left = pos + "px";
        }
    }
}