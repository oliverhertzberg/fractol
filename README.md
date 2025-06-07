# 🌀 Fractol

Fractol is a fractal explorer built in C using the [MLX42](https://github.com/codam-coding-college/MLX42) graphics library. This project was developed as part of the 42 school curriculum (Hive Helsinki), and serves as an introduction to graphics programming, user interaction, and mathematical visualization.

## 📌 Project Overview

This program renders famous fractals such as the **Mandelbrot set** and **Julia sets**. It supports real-time interaction, zooming, color variation, and dynamic parameter input to explore the infinite complexity of fractal mathematics.

## ⚙️ Features

- 🧠 Render Mandelbrot and Julia sets
- 🔍 Infinite zoom using mouse scroll
- 🎨 Dynamic color palettes to emphasize fractal depth
- 💡 Support for user-defined Julia set parameters
- 🧼 Clean exit on `ESC` key or window close
- ❌ Input validation with user-friendly parameter hints

## 🖼️ Fractals Implemented

| Fractal Type | Description |
|--------------|-------------|
| `mandelbrot` | Classic Mandelbrot set |
| `julia`      | Julia sets with user-defined parameters |

Example:
```bash
./fractol mandelbrot
./fractol julia -0.7 0.27015
