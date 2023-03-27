Mecanum Wheels
==============

Existing Research
-----------------

*   Domestic research institutions (Southeast University, Shanghai University, Harbin Institute of Technology, Zhejiang University)
*   Wang Yizhi analyzed and established the kinematic model of Mecanum four-wheel system
*   A.Gfrerrer derived an accurate kinematic model considering stick shape
*   G.Campion et al. derived the three-dimensional motion equation using matrix transformation
*   Patrick F.Muir et al. established the kinematic model considering wheel slippage
*   K.Nagatan et al. proposed a visual pose calculation algorithm considering wheel slippage
*   L.Gracia et al. derived the kinematic model considering wheel slippage using the method of successive approximation for robot dynamics.

Kinematic Forward and Inverse Solution Algorithms for Mecanum Four-Wheel Systems
--------------------------------------------------------------------------------

<aside> 💡 Based on ideal conditions </aside>

The motion of the vehicle can be expressed by the following three quantities:

$$
（\dot{x},\dot{y},\omega)
$$

We can control the speed of four motors:

$$
（\omega_1,\omega_2,\omega_3,\omega_4)
$$

To control the motion.
These two vectors are converted using the matrix $B$:

$$
\begin{bmatrix}
\omega_1\\
\omega_2\\
\omega_3\\
\omega_4\\
\end{bmatrix}
=B\cdot
\begin{bmatrix}
\dot{x}\\
\dot{y}\\
\omega\\
\end{bmatrix}
$$

![Mecanum](image/2.png)

The above figure shows the layout diagram of the Mecanum wheels used in this project.

Thanks to the work of G.Campion et al., we can directly obtain the inverse matrix $B$:

$$
B=\frac{1}{R}
\begin{bmatrix}
1&-1&-L-l\\
1&1&L+l\\
1&1&-L-l\\
1&-1&L+l\\
\end{bmatrix}
$$

Dynamic Modeling of Mecanum Wheels
----------------------------------

Definition: $m$ is the total mass of the vehicle, $J\_z$ and $J\_r$ are the moments of inertia of the vehicle around the $z$ axis and the wheels, respectively.

The Lagrangian method is used to perform dynamic modeling:

Potential energy:

$$
V=0
$$

Kinetic energy:

$$
K=\frac{1}{2}m(\dot{x}^2+\dot{y}^2)+\frac{1}{2}J_z\omega^2+\frac{1}{2}J_r\sum_{i=1}^{4}{\omega_i^2}
$$

Using the Lagrange equation:

$$
\frac{d}{dt}(\frac{\partial K}{\partial \omega_i})-\frac{\partial K}{\partial \theta_i}=T_i
$$

Solve for $(\\dot{x},\\dot{y},w)$:

$$
\bm{T}=\bm{M\cdot\ddot{\theta}}+\bm{D\cdot\dot{\theta}}
$$

where:

$$
T=(T_1,T_2,T_3,T_4)^T\\\theta=(\theta_1,\theta_2,\theta_3,\theta_4)^T\\D=diag(D_1,D_2,D_3,D_4)
$$

$T$ is the output torque of the motor, and $D$ is the coefficient matrix related to friction. The matrix $M$ is defined as:


$$
 M=\begin{bmatrix}
C&-B&B&D\\-B&C&B&D\\B&D&C&-B\\D&B&-B&C 
\end{bmatrix}\\A=\frac{mR^2}{8}\\B=\frac{J_zR^2}{16(L+l)^2}\\C=A+B+J_r\\D=A-B
$$

In subsequent algorithm design, the influence of torque $T$ should be considered.

