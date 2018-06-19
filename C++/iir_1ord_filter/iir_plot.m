clc;
clear all;
close all;
input_data = load('input_data.txt');
irr_data = load('iir_data.txt');
plot(input_data);
hold on;
figure
plot(irr_data);