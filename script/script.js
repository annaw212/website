const hamburger = document.querySelector('.hamburger');
const navLink = document.querySelector('.nav__link');

hamburger.addEventListener('click', () => {
    navLink.classList.toggle('hide');
});

$('#btnsubmit').on('click', function(e) {
    e.preventDefault();
    sender_name = $('#name').val();
    sender_email = $('#email').val();
    subject = $('#subject').val();
    message = $('#message').val();
    window.location = "mailto:anna.elise781@gmail.com?subject=" + subject + "&body=" + message;
});