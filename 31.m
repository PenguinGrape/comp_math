x = linspace(-3,3,2000);
y = 5 .* x.**4 - 2 .* x.**3 + 3 .* x.**2 + x - 2.5;
// y = x.**5 - 3 .* x.**4 + 7 .* x.**2 + x - 8;
figure();
axes();
plot(y);