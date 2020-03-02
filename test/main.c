#include <gtk/gtk.h>

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
    g_print ("Hello World2\n");
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *button_box;
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW (window), "Understand SQL File Manager");
    gtk_window_set_default_size(GTK_WINDOW (window), 600, 600);

    button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add (GTK_CONTAINER (window), button_box);

    button = gtk_button_new_with_label ("Hello World");
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
    gtk_container_add (GTK_CONTAINER (button_box), button);


    gtk_widget_show_all(window);
}

/**
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv) {
    /**
     * main()功能的目的是创建一个GtkApplication对象并运行它。
     * 在此示例中，名为的 GtkApplication指针app被调用，然后使用初始化gtk_application_new()。
     */
    GtkApplication *app;
    int status;


    /**
     * 初始化
     * gtk_application_new 方法：
     * 创建一个新的GtkApplication实例。
     * 参数：
     * application_id：应用程序ID。
     * flags：应用程序标志
     */
    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION (app), argc, argv);
    g_object_unref(app);

    return status;
}