const roles = ["Aspiring Software Engineer", "AI & ML Enthusiast", "Web Developer"];
let i = 0, j = 0, deleting = false;

function type() {
  let current = roles[i];
  document.getElementById("typing").innerText = current.substring(0, j);

  if (!deleting && j < current.length) j++;
  else if (deleting && j > 0) j--;
  else {
    deleting = !deleting;
    i = (i + 1) % roles.length;
  }

  setTimeout(type, deleting ? 50 : 100);
}
type();

// Background
const canvas = document.getElementById("bg");
const ctx = canvas.getContext("2d");

canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

let particles = [];

for (let i = 0; i < 100; i++) {
  particles.push({
    x: Math.random() * canvas.width,
    y: Math.random() * canvas.height,
    size: Math.random() * 2,
    dx: Math.random() - 0.5,
    dy: Math.random() - 0.5
  });
}

function animate() {
  ctx.clearRect(0, 0, canvas.width, canvas.height);

  particles.forEach(p => {
    p.x += p.dx;
    p.y += p.dy;

    ctx.beginPath();
    ctx.arc(p.x, p.y, p.size, 0, Math.PI * 2);
    ctx.fillStyle = "cyan";
    ctx.fill();
  });

  requestAnimationFrame(animate);
}
animate();