clc;
clear all;
close all;
input_data = load('input_data.txt')
iir_data = load('iir_data.txt')
plot(input_data,'b');
hold on;
plot(iir_data,'r');
grid on;
legend('Input','IIR',-1);