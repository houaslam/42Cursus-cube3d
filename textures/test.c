#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_data {
    void *mlx;
    void *win;
    void *img;
    int   *addr;
    int   bits_per_pixel;
    int   line_length;
    int   endian;
} t_data;

// Function to load a texture image
int load_texture(t_data *data, char *path) {
    data->img = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
    if (!data->img) {
        fprintf(stderr, "Failed to load texture image\n");
        return (0);
    }
    data->addr = (int *)mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    return (1);
}

void draw_textured_cube(t_data *data) {
    // Define cube vertices, UV coordinates, and indices
    // (Assume you have defined these data structures)

    // Bind the loaded texture
    load_texture(data, "texture.xpm");

    // Loop through vertices and draw the textured cube
    for (int i = 0; i < num_vertices; i++) {
        // Transform vertices if needed
        // (e.g., apply rotation and projection)

        int tex_x = (int)(vertices[i].u * (data->width - 1));
        int tex_y = (int)(vertices[i].v * (data->height - 1));

        int color = data->addr[tex_x + tex_y * data->line_length / (data->bits_per_pixel / 8)];

        // Use mlx_pixel_put to draw the textured point on the window
        mlx_pixel_put(data->mlx, data->win, vertices[i].x, vertices[i].y, color);
    }
}

int main() {
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "Textured Cube");

    draw_textured_cube(&data);

    mlx_loop(data.mlx);

    return 0;
}
