#lang racket
(require 2htdp/image)
(above
 (above/align "left"
              (ellipse 70 20 "solid" "gray")
              (ellipse 50 20 "solid" "darkgray")
              (ellipse 30 20 "solid" "dimgray")
              (ellipse 10 20 "solid" "black")
              (rectangle 20 40 "solid" "black"))
 (beside (triangle/saa 40 90 45 "solid" "blue")
         (rectangle 80 40 "solid" "blue")
         (triangle/ass 90 40 40 "solid" "blue")))