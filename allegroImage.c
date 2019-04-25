/*Scroll down to the bottom for the main function.
 It has all you need to know.*/

#include<stdio.h>
#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_font.h>

/*Function to draw an image. This takes in two character arrays as formal parameters
The first character array is the name of the image file to display(.png format),
and the second parameter is the array which contains the text to show.*/
/*                this|     and this|*/
int Imager(char *imageFile, char *text){
	if(!al_init()){
        printf("Could not initialize allegro.\n");
        return 1;
    }
    if(!al_install_keyboard()){
        printf("Could not initialize keyboard.\n");
        return 1;
    }
    ALLEGRO_TIMER* timer = al_create_timer(1.0/30.0);
    if(!timer){
        printf("Could not initialize timer.\n");
        return 1;
    }
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    if(!queue){
        printf("Could not initialize queue.\n");
        return 1;
    }
    ALLEGRO_DISPLAY* disp = al_create_display(1366,768);
    if(!disp){
        printf("Could not initialize display.\n");
        return 1;
    }
    ALLEGRO_FONT* font = al_create_builtin_font();
    if(!font){
        printf("Could not initialize font.\n");
        return 1;
    }

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;

    ALLEGRO_EVENT event;
    al_start_timer(timer);

    if(!al_init_image_addon()){
        printf("Could not initialize image addon");
        return 1;
    }
    ALLEGRO_BITMAP* image = al_load_bitmap(imageFile);
    if(!image){
        printf("Could not load image");
        return 1;
    }

    while(1)
    {
        al_wait_for_event(queue,&event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                //Any logic if required.
                redraw = true;
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                done = true;
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }
        if(done)
            break;
        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(244,67,54));
            al_draw_text(font, al_map_rgb(255,235,59), 120, 0, 0, text);
            al_draw_bitmap(image, 100, 100, 0);
            al_flip_display();

            redraw = false;
        }
    }
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_bitmap(image);

    return 0;
}
