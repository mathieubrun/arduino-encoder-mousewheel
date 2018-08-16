box_size=[80, 50, 25];
board_size=[20, 40, 5];

knob_h=25;
knob_r=22;

button_h=25;
button_r=10;

encoder_size=[15, 15, 15];

// board
translate([-box_size[0]/2, box_size[1]/2 - board_size[1], 0]) {
    color("green", 0.2) cube(board_size);
}

// encoder
translate([-box_size[0]/2 + box_size[1]/2, 0, box_size[2]]) {
    color("black", 0.1) {
        translate([-encoder_size[0]/2, -encoder_size[1]/2 , -encoder_size[2]]) cube(encoder_size);
        cylinder(knob_h, knob_r, knob_r);
    } 
}

// buttons
translate([box_size[0]/2 - box_size[1]/3, 0, box_size[2] - button_h + 5]) {
    offset = (box_size[1]/2 - button_r * 2) / 3 + button_r;
    color("red", 0.1) {
        translate([0, offset, 0]) cylinder(button_h, button_r, button_r);
        translate([0, -offset, 0]) cylinder(button_h, button_r, button_r);
    }
}

// box
translate([-box_size[0]/2, -box_size[1]/2, 0]) {
    color("blue", 0.1) cube(box_size);
}

