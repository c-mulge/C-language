<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $name = $_POST["name"];
  $email = $_POST["email"];
  $phone = $_POST["phone"];
  $message = $_POST["message"];
  $date = $_POST["date"];
  $time = $_POST["time"];

  // Perform any additional processing or validation of the form data

  // Example: Store the form data in a database
  // Replace 'your-database-credentials' with your actual database credentials
  $servername = 'your-database-servername';
  $username = 'your-database-username';
  $password = 'your-database-password';
  $database = 'your-database-name';

  // Create a connection to the database
  $conn = new mysqli($servername, $username, $password, $database);

  // Check connection
  if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
  }

  // Prepare and execute the database query
  $sql = "INSERT INTO contact_form_data (name, email, phone, message, date, time) VALUES (?, ?, ?, ?, ?, ?)";
  $stmt = $conn->prepare($sql);
  $stmt->bind_param("ssssss", $name, $email, $phone, $message, $date, $time);
  $stmt->execute();

  // Close the database connection
  $stmt->close();
  $conn->close();

  // Send a response back to the client
  echo "Thank you for contacting us! We will get back to you shortly.";
}
?>
