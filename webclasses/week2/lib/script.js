// First, add DOM event listener

document.addEventListener("DOMContentLoaded", function(){

    // Creating Canvas
    const canvas = document.querySelector('#canvas');
    canvas.style.border = "2px solid black";

    // Creating Canvas 2D rendering context
    const ctx = canvas.getContext("2d");

    // Setting initial values
    // airplane
    const plane = document.querySelector('#plane');
    plane.width = 100;
    plane.height = 100;
    let plane_x = canvas.width/2;
    let plane_y = canvas.height/2;
    let plane_hit = false;
    // missile
    const missile = document.querySelector('#missile');
    missile.width = 30;
    missile.height = 30;
    let missile_x = 0;
    let missile_y = canvas.height/2;
    let missile_launched = false;
    // explosion
    const explosion = document.querySelector('#explosion');

    // Setting sound 
    const sound = document.querySelector("#sound");
    const soundfx = document.querySelector("#soundfx");
    soundfx.checked = true; // starting with sound

    // Sound function
    soundfx.addEventListener("click", function(){
        if(!this.checked){
            sound.volume = 0;
        }
        else{
            sound.volume = 1;
        }
    });

    // Catching mouse movements
    function refresh(){
        canvas.addEventListener("mousemove", function(e){
            // Avoid the plane from being over the missile
            if (e.clientX >= missile.width + plane.width){
                plane_x = e.clientX - plane.width;
            }            
            // Avoid plane get out the canvas
            if (e.clientY <= canvas.height - plane.height/2){
                plane_y = e.clientY - plane.height/2;
            }
            missile_y = plane_y + 10;
        });
        // Mouse click starts/pauses the missile
        canvas.addEventListener("click", function(){
            if(!missile_launched)
                missile_launched = true;
            else
                missile_launched = false;
        });
    }

    // Animation
    function animation(){
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        if (missile_launched){
            missile_x+=5;
        }
        // Detecting collision
        if (missile_launched && missile_x >= plane_x - missile.width + 30){
            plane_hit = true;
        }
        // Refresh Coordinates
        ctx.drawImage(missile, missile_x, missile_y, missile.width, missile.height);
        ctx.drawImage(plane, plane_x, plane_y, plane.width, plane.height);
        // If it haven't collided yet
        if (!plane_hit){
            window.requestAnimationFrame(animation);
        } else {
            // After collison happens
            ctx.drawImage(explosion, plane_x-30, plane_y-20, explosion.width*0.3, explosion.height*0.3);
            sound.currentTime = 1;
            if (soundfx.checked){
                sound.play();
            }
        }
    }

    refresh();
    animation();

});