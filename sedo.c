import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp

# Definição dos parâmetros
beta = 0.1  # Taxa de transmissão
nu = 0.9     # Taxa de recuperação
N = 1000     # População total

# Condições iniciais
S0 = 990
I0 = 10
R0 = 0

# Equações diferenciais do modelo SIR
def sir(t, y):
    S, I, R = y
    dSdt = -beta * S * I / N
    dIdt = beta * S * I / N - nu * I
    dRdt = nu * I
    return [dSdt, dIdt, dRdt]

# Intervalo de tempo para a simulação
t_span = (0, 160)  # Simular por 160 dias
t_eval = np.linspace(*t_span, 1000)  # 1000 pontos no tempo

# Resolver o sistema
sol = solve_ivp(sir, t_span, [S0, I0, R0], t_eval=t_eval)

# Plotar os resultados
plt.figure(figsize=(10, 6))
plt.plot(sol.t, sol.y[0], label="Suscetíveis (S)")
plt.plot(sol.t, sol.y[1], label="Infectados (I)", color="red")
plt.plot(sol.t, sol.y[2], label="Removidos (R)", color="green")
plt.xlabel("Dias")
plt.ylabel("Número de indivíduos")
plt.title("Evolução do modelo SIR")
plt.legend()
plt.grid()
plt.show()
