#include <gtk/gtk.h>

GtkWidget *aboutWindow;

int main(int argc, char * argv[]){
	gtk_init(&argc, &argv);

	GtkBuilder *builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "CrystalBall.glade", NULL);

	GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
	gtk_builder_connect_signals(builder, NULL);

	aboutWindow = GTK_WIDGET(gtk_builder_get_object(builder, "aboutWindow"));

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

	return 0;
}

void windowDestroyed(){
	gtk_main_quit();
}

void ask() {
	printf("ask question\n");
}

void clear() {
	printf("clear transcript\n");
}

void about() {
	gtk_widget_show(aboutWindow);
}
