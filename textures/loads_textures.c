
#include "../parsing/parsing.h"

void    loads_images(t_textures *txt, char *path)
{
    int w;
    int h;

    (*txt).img = mlx_xpm_file_to_image((*txt).map->window->mlx, path, &w, &h);
    if (!(*txt).img)
        put_error("INVALID NORTH IMAGE");
    (*txt).h = h;///// what if i tried txt-> instead
    (*txt).w = w;
    (*txt).add = (int *)mlx_get_data_addr((*txt).img, &(*txt).bits_per_pixel, &(*txt).line_length, &(*txt).endian);
}

void    loads_textures(t_textures *txt)
{
	loads_images(&txt[NO], txt->map->directions->no);
	loads_images(&txt[SO], txt->map->directions->so);
	loads_images(&txt[EA], txt->map->directions->ea);
	loads_images(&txt[WE], txt->map->directions->we);
	// for (int i = 0; i < num_vertices; i++) {
	// 	// Transform vertices if needed
	// 	// (e.g., apply rotation and projection)

	// 	int tex_x = (int)(vertices[i].u * (data->width - 1));
	// 	int tex_y = (int)(vertices[i].v * (data->height - 1));

	// 	int color = data->addr[tex_x + tex_y * data->line_length / (data->bits_per_pixel / 8)];

	// 	// Use mlx_pixel_put to draw the textured point on the window
	// 	mlx_pixel_put(data->mlx, data->win, vertices[i].x, vertices[i].y, color);
	// }
}
