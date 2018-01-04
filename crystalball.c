//Copyright (C) 2017 Arc676/Alessandro Vinciguerra

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation (version 3)

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.
//See README and LICENSE for more details

#include <gtk/gtk.h>

GtkWidget *aboutWindow;
GtkTextBuffer *transcript;

void windowDestroyed(){
	gtk_main_quit();
}

void ask() {
	GtkTextIter end;
	gtk_text_buffer_get_end_iter(transcript, &end);
	gtk_text_buffer_insert(transcript, &end, "test\n", -1);
}

void clear() {
	gtk_text_buffer_set_text(transcript, "Crystal Ball Transcript\n", -1);
}

void about() {
	gtk_widget_show(aboutWindow);
}

int main(int argc, char * argv[]){
	gtk_init(&argc, &argv);

	GtkBuilder *builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "CrystalBall.glade", NULL);

	GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
	gtk_builder_connect_signals(builder, NULL);

	aboutWindow = GTK_WIDGET(gtk_builder_get_object(builder, "aboutWindow"));

	GtkTextView* transcriptView = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "transcript"));
	transcript = gtk_text_view_get_buffer(transcriptView);

	g_object_unref(builder);

	clear();

	gtk_widget_show(window);
	gtk_main();


	return 0;
}

