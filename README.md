# fdf

Very basic program that draws an isometric grid.  

Uses a custom library (written by 42's staff) that only allows to draw one pixel at a time.  
I had to come up with the grid drawing algorithm myself.

## File format

Grid of space separated integers.

```
o--------------------> X-axis
| N N N N N N ...
| N N N N N N ...
| N N N N N N ...
| N N N N N N ...
| ...............
V
Y-axis
```

Where each N is a Z-axis altitude

## Example :

### Input :
![](https://i.imgur.com/4kgcvwt.png)

### Output :
![](https://i.imgur.com/sSwFxBg.png)
