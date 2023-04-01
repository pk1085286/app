import Firebase

// Initialize Firebase app
FirebaseApp.configure()

// Reference to the database root node
let databaseRef = Database.database().reference()

// Create a new user entry in the database
func createUser(uid: String, name: String, email: String) {
  let userRef = databaseRef.child("users").child(uid)
  userRef.setValue([
    "name": name,
    "email": email,
    "bookings": []
  ])
}

// Retrieve a user's bookings from the database
func getUserBookings(uid: String, completion: @escaping ([String]) -> Void) {
  let userRef = databaseRef.child("users").child(uid).child("bookings")
  userRef.observeSingleEvent(of: .value, with: { snapshot in
    if let bookings = snapshot.value as? [String] {
      completion(bookings)
    } else {
      completion([])
    }
  })
}

// Add a new booking to a user's bookings
func addBookingToUser(uid: String, bookingId: String) {
  let userRef = databaseRef.child("users").child(uid)
  userRef.child("bookings").observeSingleEvent(of: .value, with: { snapshot in
    if var bookings = snapshot.value as? [String] {
      bookings.append(bookingId)
      userRef.child("bookings").setValue(bookings)
    } else {
      userRef.child("bookings").setValue([bookingId])
    }
  })
}

// Create a new booking entry in the database
func createBooking(destination: String, date: String, uid: String) -> String {
  let bookingRef = databaseRef.child("bookings").childByAutoId()
  let bookingId = bookingRef.key ?? ""
  bookingRef.setValue([
    "destination": destination,
    "date": date,
    "user_id": uid
  ])
  addBookingToUser(uid: uid, bookingId: bookingId)
  return bookingId
}
