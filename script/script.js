function toggleMenu() {
    const dropdownMenu = document.querySelector('.dropdown-menu');
    const navbar = document.getElementById('navbar');
    navbar.classList.toggle('show');
    dropdownMenu.classList.toggle('show');
}


// // Smooth scrolling for navbar links
// const navbarLinks = document.querySelectorAll('.nav-link');

// navbarLinks.forEach(link => {
//   link.addEventListener('click', event => {
//     event.preventDefault();
//     const targetId = link.getAttribute('href');
//     const targetSection = document.querySelector(targetId);
//     const topOffset = 0; // Adjust this value to offset any fixed header or other elements
//     const elementPosition = targetSection.getBoundingClientRect().top;
//     const offsetPosition = elementPosition - topOffset;

//     window.scrollBy({
//       top: offsetPosition,
//       behavior: 'smooth'
//     });
//   });
// });

