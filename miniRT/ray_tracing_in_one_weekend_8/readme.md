## 8.2->8.3으로 갈 때는

color.c파일의 void	write_color(t_color pixel_color, int samples_per_pixel)함수에서
```c
r = pixel_color.x * scale;
g = pixel_color.y * scale;
b = pixel_color.z * scale;
```
를
```c
r = sqrt(pixel_color.x * scale);
g = sqrt(pixel_color.y * scale);
b = sqrt(pixel_color.z * scale);
```
와 같이 sqrt로 감싸주면 됩니다.